# Rules of map
>- Floor must be indicated as zero(0)
>- Walls in map must be value form 1 to 5 included
>- Player must be indicated as capital X

>- The map must contain the same number of columns
>- Map must be surrounded by walls
>- Map must have EOF(end of file)
>- Map must contain only one player
>- Between walls or player or floor must be space or tab
### Example of valid maps
```
1 1 1
1 X 1
1 1 1

1 1 1 1
1 0 0 1
1 X 0 1
1 1 1 1

1 1 1 1 1	1 1 1 1 1 1
1 0 0 0 0 0 	0 0 0 0 1
1 0 5 0 5 0 5 0 5 0 1
1 0 0 0 0 0 0 0	 0 0 1
1 0 4 0 4 0 4 0	 4 0 1
1 X 0 0 0 0 0 0	 0 0 1
1 0 3 0 3 0 3	 0 3 0 1
1 0 0 0 0 0 0	 0 0 0 1
1 0 2 0 2	 0 2 0 2 0 1
1 0 0 0 	0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1
```
### Example of invalid map
```
Not surrounded by walls:
1 0 4
1 X 3
1 1 2

wrong number of columns:
1 1 1 1
1 X 1
1 1 1

wrong spacing:
11 1
1 X 1
1 1 1

wrong wall indication:
1 7 1
1 X 1
1 1 1

```