/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    while (par[x] != x)
        x = par[x];
    return x;
}

void unionSet(int par[], int x, int z) {
    // add code here.
    par[find(par, x)] = find(par, z);
    par[find(par, z)] = find(par, x);
}