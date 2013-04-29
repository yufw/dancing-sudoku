struct node {
    struct node *left, *right, *up, *down;
    struct node *ch;
    int r, c, s;
};

struct node * init(int nrow, int ncol);
void insert(struct node *h, int r, int c);
void cover(struct node *p);
void uncover(struct node *p);
void delete_rhead(struct node *h);
int search(struct node *h, int i, struct node *solution[]);
