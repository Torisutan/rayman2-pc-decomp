#ifndef SAI_CODEC_H
#define SAI_CODEC_H

#include <stdio.h>

typedef struct bit_file {
    FILE          *file;
    unsigned char  mask;
    int            rack;
    int            pacifier_counter;
} BIT_FILE;

/* 0x004A6784 */
extern unsigned char DAT_004a6784;

/* 0x0048D2A0 */
void FUN_0048d2a0(void);

/* 0x0048D2C0 */
void FUN_0048d2c0(char *src, char *dst, char mode);
unsigned char FUN_0048d370(char *src, char *dst, char mode);

#define INDEX_BIT_COUNT      12
#define LENGTH_BIT_COUNT     4
#define WINDOW_SIZE          ( 1 << INDEX_BIT_COUNT )
#define RAW_LOOK_AHEAD_SIZE  ( 1 << LENGTH_BIT_COUNT )
#define BREAK_EVEN           1
#define LOOK_AHEAD_SIZE      ( RAW_LOOK_AHEAD_SIZE + BREAK_EVEN )
#define TREE_ROOT            WINDOW_SIZE
#define END_OF_STREAM        0
#define UNUSED               0
#define MOD_WINDOW( a )      ( ( a ) & ( WINDOW_SIZE - 1 ) )

typedef struct SAI_tdstLZSSNode {
    int parent;
    int smaller_child;
    int larger_child;
} SAI_tdstLZSSNode;

extern unsigned char window[WINDOW_SIZE];          /* 0x004E9740 */
extern SAI_tdstLZSSNode tree[WINDOW_SIZE + 1];     /* 0x004EA740 */

extern unsigned char DAT_004a6798;
extern char DAT_004b9c38;
extern int  DAT_004b9c3c;
extern int  DAT_004b9c40;
extern char DAT_004f6760[256][8];

extern signed char DAT_004f6f68;
unsigned char FUN_0048d420(unsigned char v);       /* 0x0048D420 */
unsigned char FUN_0048d450(FILE *f);               /* 0x0048D450 */
void FUN_0048d470(unsigned char b, FILE *f);       /* 0x0048D470 */
unsigned long FUN_0048d4b0(FILE *f);               /* 0x0048D4B0 */
void FUN_0048d4d0(unsigned long v, FILE *f);       /* 0x0048D4D0 */
int  FUN_0048d500(FILE *f);                        /* 0x0048D500 */
int  FUN_0048d530(int v, FILE *f);                 /* 0x0048D530 */
int  FUN_0048d5a0(FILE *f);                        /* 0x0048D5A0 */
int  FUN_0048d610(int c, FILE *f);                 /* 0x0048D610 */
void FUN_0048d660(void);                           /* 0x0048D660 */
extern char DAT_004f6f60[8];                       /* 0x004F6F60 */
void FUN_0048d6b0(FILE *in, FILE *out);            /* 0x0048D6B0 */
void FUN_0048d890(FILE *in, FILE *out);            /* 0x0048D890 */

void InitTree(int r);                              /* 0x0048DE80 */
void ContractNode(int old_node, int new_node);     /* 0x0048DEB0 */
void ReplaceNode(int old_node, int new_node);      /* 0x0048DF10 */
int  FindNextNode(int node);                       /* 0x0048DFA0 */
void DeleteString(int p);                          /* 0x0048DFD0 */
int  AddString(int new_node, int *match_position); /* 0x0048E040 */
void CompressFile(FILE *input, BIT_FILE *output);  /* 0x0048E120 */
void ExpandFile(BIT_FILE *input, FILE *output);    /* 0x0048E290 */

BIT_FILE     *OpenOutputBitFile(char *name);   /* 0x0048DA90 */
BIT_FILE     *OpenInputBitFile(char *name);    /* 0x0048DAE0 */
void          CloseOutputBitFile(BIT_FILE *bit_file);  /* 0x0048DB30 */
void          CloseInputBitFile(BIT_FILE *bit_file);   /* 0x0048DBC0 */
void          OutputBit(BIT_FILE *bit_file, int bit);  /* 0x0048DBE0 */
void          OutputBits(BIT_FILE *bit_file, unsigned long code, int count); /* 0x0048DC80 */
int           InputBit(BIT_FILE *bit_file);    /* 0x0048DD40 */
unsigned long InputBits(BIT_FILE *bit_file, int bit_count);  /* 0x0048DDD0 */

#endif
