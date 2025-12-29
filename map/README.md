Format des fichiers de map

Chaque map est un fichier texte contenant une grille rectangulaire entourée de murs.
Les caractères reconnus sont :

- `#` : mur
- `P` : joueur (exactement un)
- `X` : caisse
- `O` : emplacement de stockage (but)
- ` ` : espace vide

Exécution :

```bash
./my_sokoban map/<nom_de_map>.txt
```

Maps fournies :

- `easy.txt` : map simple pour tests rapides
- `medium.txt` : map de difficulté moyenne
- `blocked.txt` : exemple intensionnellement difficile/insolvable
- `large.txt` : map plus grande pour tester l'affichage

Note : les fichiers doivent être encodés en UTF-8 et chaque ligne doit se terminer par un saut de ligne.
