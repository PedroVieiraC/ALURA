
void allocmap()
{
    // part of code to dynamic alloc the map
    map.matriz = malloc(sizeof(char *) * map.lines);
    for (int i = 0; i < map.lines; i++)
    {
        map.matriz[i] = malloc(sizeof(char) * (map.columns + 1));
    }
}

void readmap()
{
    FILE *f;
    f = fopen("map.txt", "r");
    if (!f)
    {
        printf("Can't open the map file\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(map.lines), &(map.columns));

    allocmap();

    for (int i = 0; i < map.lines; i++)
    {
        fscanf(f, "%s", map.matriz[i]);
    }
    fclose(f);
}

void freememory()
{
    for (int i = 0; i < map.lines; i++)
    {
        free(map.matriz[i]);
    }
    free(map.matriz);
}

void printgame()
{
    for (int i = 0; i < map.lines; i++)
    {
        printf("%s\n", map.matriz[i]);
    }
}