<<<<<<< HEAD
# Maps valides — tests parsing cub3d

Chaque fichier doit être **accepté** par ton parsing (aucune erreur, joueur trouvé,
map fermée). Sert à vérifier que tu ne rejettes pas du valide par erreur.

| Fichier | Particularité testée |
|---------|----------------------|
| `01_simple.cub` | Cas minimal, joueur N |
| `02_player_S.cub` | Joueur S, couleurs aux bornes (0 et 255) |
| `03_player_E.cub` | Identifiants dans le désordre, joueur E |
| `04_player_W.cub` | Joueur W |
| `05_irregular_shape.cub` | Map non rectangulaire mais fermée |
| `06_inner_walls.cub` | Murs internes (îlot de 1) — légal |
| `07_leading_spaces_walls.cub` | Espaces en début de ligne + lignes de largeurs différentes |
| `08_enclosed_space_inside.cub` | Espace ` ` interne entièrement entouré de murs — légal |

## Note importante

`05`, `07` et `08` sont les pièges classiques : un parsing trop strict (qui exige
un rectangle, ou qui rejette tout espace) les refuse à tort. Un flood-fill correct
les accepte car aucune case marchable (`0`/joueur) ne touche l'extérieur.

```sh
for f in maps/valid/*.cub; do
    echo "=== $f ==="; ./cub3D "$f"; echo "(exit: $?)"
done
```
=======
# Maps valides — tests parsing cub3d

Chaque fichier doit être **accepté** par ton parsing (aucune erreur, joueur trouvé,
map fermée). Sert à vérifier que tu ne rejettes pas du valide par erreur.

| Fichier | Particularité testée |
|---------|----------------------|
| `01_simple.cub` | Cas minimal, joueur N |
| `02_player_S.cub` | Joueur S, couleurs aux bornes (0 et 255) |
| `03_player_E.cub` | Identifiants dans le désordre, joueur E |
| `04_player_W.cub` | Joueur W |
| `05_irregular_shape.cub` | Map non rectangulaire mais fermée |
| `06_inner_walls.cub` | Murs internes (îlot de 1) — légal |
| `07_leading_spaces_walls.cub` | Espaces en début de ligne + lignes de largeurs différentes |
| `08_enclosed_space_inside.cub` | Espace ` ` interne entièrement entouré de murs — légal |

## Note importante

`05`, `07` et `08` sont les pièges classiques : un parsing trop strict (qui exige
un rectangle, ou qui rejette tout espace) les refuse à tort. Un flood-fill correct
les accepte car aucune case marchable (`0`/joueur) ne touche l'extérieur.

```sh
for f in maps/valid/*.cub; do
    echo "=== $f ==="; ./cub3D "$f"; echo "(exit: $?)"
done
```
>>>>>>> 5b3d607 (Feat : Parsing)
