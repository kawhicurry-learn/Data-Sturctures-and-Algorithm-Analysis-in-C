#include "_HashQuad.h"
#include <stdio.h>
int         MinTableSize;
ElementType Hash(const ElementType key, int TableSize) {
    return 0;  // Hash function can be variable.
}
enum KindOfEntry { Legitimate, Empty, Deleted };
struct HashEntry {
    ElementType      Element;
    enum KindOfEntry Info;
};
typedef struct HashEntry Cell;
struct HashTbl {
    int   TableSize;
    Cell *TheCells;
};

int NextPrime(int TableSize) {
    int i = TableSize, j;
    while (i++) {
        if (i % 2 == 0) {
            continue;
        }
        for (j = 3; i > j / 2; j += 2) {
            if (i % j == 0) {
                continue;
            }
        }
    }
    return i;
}
HashTable InitializeTable(int TableSize) {
    HashTable H;
    int       i;
    if (TableSize < MinTableSize) {
        perror("Table size is too small");
        return NULL;
    }
    H = (HashTable)malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        perror("out of space");
        exit(1);
    }
    H->TableSize = NextPrime(TableSize);
    H->TheCells  = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheCells == NULL) {
        perror("out of space");
        exit(1);
    }
    for (i = 0; i < H->TableSize; i++) {
        H->TheCells[i].Info = Empty;
    }
}
Position Find(ElementType Key, HashTable H) {
    Position CurrentPos   = Hash(Key, H->TableSize);
    int      CollisionNum = 0;
    while (H->TheCells[CurrentPos].Info != Empty
           && H->TheCells[CurrentPos].Element != Key) {
        CurrentPos += 2 * ++CollisionNum - 1;
        if (CurrentPos >= H->TableSize) {
            CurrentPos -= H->TableSize;
        }
    }
    return CurrentPos;
}
void Insert(ElementType Key, HashTable H) {
    Position Pos = Find(Key, H);
    if (H->TheCells[Pos].Info != Legitimate) {
        H->TheCells[Pos].Info    = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}
HashTable Rehash(HashTable H) {
    int   i, OldSize;
    Cell *OldCells;
    OldCells = H->TheCells;
    OldSize  = H->TableSize;
    H        = InitializeTable(2 * OldSize);
    for (i = 0; i < OldSize; i++) {
        if (OldCells[i].Info == Legitimate) {
            Insert(OldCells[i].Element, H);
        }
    }
    free(OldCells);
    return H;
}