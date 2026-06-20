<<<<<<< HEAD
# Maps invalides — tests parsing cub3d

Chaque fichier doit faire **échouer** ton parsing avec un message d'erreur propre
(`Error\n` suivi d'une explication selon le sujet) et **sans crash / sans fuite**.

| Fichier | Erreur testée |
|---------|---------------|
| `01_bad_extension.cu` | Extension différente de `.cub` |
| `02_missing_texture_NO.cub` | Identifiant de texture manquant (NO) |
| `03_duplicate_texture.cub` | Texture déclarée deux fois (NO) |
| `04_bad_texture_path.cub` | Chemin de texture inexistant / illisible |
| `05_color_out_of_range.cub` | Composante RGB > 255 |
| `06_color_negative.cub` | Composante RGB négative |
| `07_color_missing_component.cub` | Couleur incomplète (2 valeurs au lieu de 3) |
| `08_color_not_numeric.cub` | Couleur non numérique (`abc`) |
| `09_map_not_closed_top.cub` | Map non fermée (ligne du haut) |
| `10_map_not_closed_side.cub` | Map non fermée (bord droit) |
| `11_player_on_edge.cub` | Joueur sur un bord (donc map ouverte) |
| `12_no_player.cub` | Aucun joueur (N/S/E/W absent) |
| `13_two_players.cub` | Deux positions de joueur |
| `14_invalid_char.cub` | Caractère interdit dans la map (`X`) |
| `15_hole_in_wall.cub` | Trou dans le mur extérieur |
| `16_empty_line_inside_map.cub` | Ligne vide au milieu de la map |
| `17_empty_file.cub` | Fichier vide |
| `18_no_map.cub` | Identifiants présents mais pas de map |
| `19_content_after_map.cub` | Contenu après la map |
| `20_unknown_identifier.cub` | Identifiant inconnu (`XY`) |
| `21_color_over_255_multi.cub` | Toutes les composantes hors plage |
| `22_isolated_zero.cub` | Espace ouvert sur l'extérieur (0 atteignant le vide) |

## Lancer en lot

```sh
for f in maps/invalid/*.cub maps/invalid/*.cu; do
    echo "=== $f ==="
    ./cub3D "$f"
    echo "(exit: $?)"
done
```

Pour chaque map, vérifie aussi l'absence de fuite avec `valgrind --leak-check=full`.
=======
# Maps invalides — tests parsing cub3d

Chaque fichier doit faire **échouer** ton parsing avec un message d'erreur propre
(`Error\n` suivi d'une explication selon le sujet) et **sans crash / sans fuite**.

| Fichier | Erreur testée |
|---------|---------------|
| `01_bad_extension.cu` | Extension différente de `.cub` |
| `02_missing_texture_NO.cub` | Identifiant de texture manquant (NO) |
| `03_duplicate_texture.cub` | Texture déclarée deux fois (NO) |
| `04_bad_texture_path.cub` | Chemin de texture inexistant / illisible |
| `05_color_out_of_range.cub` | Composante RGB > 255 |
| `06_color_negative.cub` | Composante RGB négative |
| `07_color_missing_component.cub` | Couleur incomplète (2 valeurs au lieu de 3) |
| `08_color_not_numeric.cub` | Couleur non numérique (`abc`) |
| `09_map_not_closed_top.cub` | Map non fermée (ligne du haut) |
| `10_map_not_closed_side.cub` | Map non fermée (bord droit) |
| `11_player_on_edge.cub` | Joueur sur un bord (donc map ouverte) |
| `12_no_player.cub` | Aucun joueur (N/S/E/W absent) |
| `13_two_players.cub` | Deux positions de joueur |
| `14_invalid_char.cub` | Caractère interdit dans la map (`X`) |
| `15_hole_in_wall.cub` | Trou dans le mur extérieur |
| `16_empty_line_inside_map.cub` | Ligne vide au milieu de la map |
| `17_empty_file.cub` | Fichier vide |
| `18_no_map.cub` | Identifiants présents mais pas de map |
| `19_content_after_map.cub` | Contenu après la map |
| `20_unknown_identifier.cub` | Identifiant inconnu (`XY`) |
| `21_color_over_255_multi.cub` | Toutes les composantes hors plage |
| `22_isolated_zero.cub` | Espace ouvert sur l'extérieur (0 atteignant le vide) |

## Lancer en lot

```sh
for f in maps/invalid/*.cub maps/invalid/*.cu; do
    echo "=== $f ==="
    ./cub3D "$f"
    echo "(exit: $?)"
done
```

Pour chaque map, vérifie aussi l'absence de fuite avec `valgrind --leak-check=full`.
>>>>>>> 5b3d607 (Feat : Parsing)
