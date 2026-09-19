# Recap cub3D — corrections

## État final

| Contrôle | Avant | Après |
|---|---|---|
| Compilation `-Wall -Wextra -Werror` | OK | OK, 0 warning |
| Norminette | 4 erreurs | **0 erreur** |
| Maps valides acceptées | 26/33 | **33/33** |
| Maps invalides rejetées | ~50/65 | **63/65** (les 2 restantes = fixtures, voir « À faire ») |
| Valgrind (parsing + rendu) | non testé | **0 fuite, 0 erreur** |
| Relink inutile (`make` 2×) | relink systématique | « Rien à faire » |

---

## 1. Bugs de rendu (les plus graves)

**Textures assignées aux mauvaises faces.** En regardant au nord on affichait la texture `SO`, à l'est la `WE`, etc. Les 4 directions étaient inversées (prouvé avec `textures/test/{north,south,east,west}.xpm`).

**Textures affichées en miroir.** La condition de flip de `texx` était inversée sur les deux axes.

| | Avant | Après |
|---|---|---|
| Joueur N | `S` inversé | `N` correct |
| Joueur S | `N` inversé | `S` correct |
| Joueur E | `W` inversé | `E` correct |
| Joueur W | `E` inversé | `W` correct |

`src/game/textures.c` — `choose_text()` et `clamp_texx()`.

**Lecture hors des chaînes dans le DDA.** `normalize_map()` ne mettait pas les lignes à la même largeur et `dda()` n'avait aucun test de bornes : lecture hors chaîne sur toute carte non rectangulaire (dont la map du sujet). La grille est maintenant rectangulaire (`pad_line()`) et `dda()` passe par `is_wall()` qui borne x et y.

**Division par zéro / `NaN`.** `lineheight = sizey / perpwall` avec `perpwall` nul ou négatif → `inf`/`NaN` puis `(int)NaN` (comportement indéfini). `calc_render()` borne `perpwall` et `lineheight`.

**Retours MiniLibX testés à tort.** `mlx_put_image_to_window()` et `mlx_get_screen_size()` ne renvoient rien d'exploitable. Ces tests sont supprimés.

**Joueur sur un coin de case.** Il démarre maintenant au centre de la case (`+0.5`).

---

## 2. Rendu — performance et structure

- `mlx_get_data_addr()` était rappelé 2 fois par colonne. Les adresses sont résolues une fois à l'init dans une struct `t_tex`.
- `t_imag` : 18 champs plats remplacés par 4 `t_tex`.
- Ajout d'un hook `Expose` : la fenêtre se redessine quand elle est recouverte puis redécouverte.

---

## 3. Parsing durci

| Cas | Avant | Après |
|---|---|---|
| `NOPE ./t.xpm`, `FOO 1,2,3` | accepté | rejeté (match exact) |
| Texture ou couleur dupliquée | ignorée | **erreur** |
| `F` ou `C` absent | `0,0,0` par défaut | **erreur** |
| Texture = dossier | accepté | rejeté |
| Texture sans `.xpm` | accepté | rejeté |
| `.cub` illisible / vide / dossier | message trompeur | message correct |
| `255,255,255,` / `1,2` | accepté | rejeté |
| Composante à 5 chiffres | débordement `ft_atoi` | rejetée |
| 2 joueurs | détecté par le flood fill seulement | détecté au comptage |
| Joueur en colonne/ligne 0 | confondu avec « absent » | comptage réel |
| CRLF | `\r` = caractère invalide | géré |
| Tabulation comme séparateur | ligne ignorée | gérée |

Les identifiants ne sont cherchés que dans les 6 premières lignes non vides.

---

## 4. Fuites et robustesse

- `free_struct()` n'était jamais appelé quand le parsing échouait.
- `init_window()` fuyait sur chacun de ses chemins d'échec.
- Buffer statique de `get_next_line` non libéré en arrêt anticipé → `drain_gnl()`.
- `rest_is_blank()` fuyait la ligne sur son retour d'échec.
- `free_img()` ne remettait pas les pointeurs à `NULL`.
- `set_textures()` faisait `return (NULL)` depuis une fonction `bool`.
- Code de sortie `-1` (255) → `1`; messages sur **stderr** au format `Error\n`.

---

## 5. Code mort et norme

- Supprimé `src/window/ceilnfloor.c` (référençait un champ `img->back` inexistant).
- Supprimé `src/parsing/map_parse.c` (code commenté + `read_map()` au test inversé).
- Supprimé les déclarations fantômes du header (`handle_keyrelease`, `set_heigth`, `map_count_line`, `create_back`, `draw_back`).
- Norminette : lignes > 80 col., indentation espaces, camelCase, espacement, 3 fichiers > 5 fonctions scindés en `flood_utils.c`, `color_utils.c`, `texture_check.c`.
- Makefile réécrit : dépendance sur `game.h`, plus de relink systématique, cibles mortes supprimées.

---

## 6. Données du projet

- `textures/{north,south,east,west}.xpm` faisaient 0 octet : remplies depuis `textures/test/`.
- `maps/default.cub` pointait sur `obj-7.xpm` (le fichier est `obj4-7.xpm`).
- `maps/valid/05_irregular_shape.cub` était réellement ouverte : mur ajouté.
- `maps/valid/08_enclosed_space_inside.cub` était un doublon de la version `invalid/` : reconstruite (CRLF conservés).

---

## À faire

1. `maps/invalid/forbidden.cub` et `textures_forbidden.cub` testent des fichiers sans droit de lecture, mais git ne conserve pas `chmod 000`. Le code les gère (vérifié à la main) :
   `chmod 000 maps/invalid/forbidden.cub maps/invalid/textures_forbidden.cub`
2. `cub.zip` (3,3 Mo) et `src/test.zip` (88 Ko) sont suivis par git — à retirer.
3. `minilibx-linux/` est exclu par le `.gitignore` : vérifier que le correcteur l'aura.
4. Rien n'est commité. Nouveaux fichiers : `parse_elements.c`, `parse_line.c`, `flood_utils.c`, `color_utils.c`, `texture_check.c`.
