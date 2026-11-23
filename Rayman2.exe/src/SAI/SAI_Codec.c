#include <stdio.h>
#include <stdlib.h>

#include "ERM/CpaError.h"
#include "SAI/SAI_Codec.h"

/* 0x004A6784 */
unsigned char DAT_004a6784 = 0xFF;

/* 0x0048D2A0 */
void FUN_0048d2a0(void)
{
    if (DAT_004a6784 == 0xff)
        DAT_004a6784 = Erm_fn_ucInitErrMsg();
}

/* 0x0048D2C0 */
void FUN_0048d2c0(char *src, char *dst, char mode)
{
    FILE *in;
    FILE *out;
    BIT_FILE *bit_out;

    if (mode == 1) {
        in = fopen(src, "rb");
        if (in != NULL) {
            bit_out = OpenOutputBitFile(dst);
            if (bit_out != NULL) {
                CompressFile(in, bit_out);
                CloseOutputBitFile(bit_out);
            }
            fclose(in);
        }
    }
    if (mode == 2) {
        in = fopen(src, "rb");
        if (in != NULL) {
            out = fopen(dst, "wb");
            if (out != NULL) {
                FUN_0048d6b0(in, out);
                fclose(out);
            }
            fclose(in);
        }
    }
}

/* 0x0048D370 */
unsigned char FUN_0048d370(char *src, char *dst, char mode)
{
    BIT_FILE *bit_in;
    FILE *in;
    FILE *out;
    unsigned char ok;

    ok = 0;
    if (mode == 1) {
        bit_in = OpenInputBitFile(src);
        if (bit_in != NULL) {
            out = fopen(dst, "wb");
            if (out != NULL) {
                ExpandFile(bit_in, out);
                ok = 1;
                fclose(out);
            }
            CloseInputBitFile(bit_in);
        }
    }
    if (mode == 2) {
        in = fopen(src, "rb");
        if (in != NULL) {
            out = fopen(dst, "wb");
            if (out != NULL) {
                FUN_0048d890(in, out);
                ok = 1;
                fclose(out);
            }
            fclose(in);
        }
    }
    return ok;
}

unsigned char DAT_004a6798 = 0x53;          /* 0x004A6798 */
char DAT_004b9c38;                          /* 0x004B9C38 */
int  DAT_004b9c3c;                          /* 0x004B9C3C */
int  DAT_004b9c40;                          /* 0x004B9C40 */
unsigned char window[WINDOW_SIZE];          /* 0x004E9740 */
SAI_tdstLZSSNode tree[WINDOW_SIZE + 1];     /* 0x004EA740 */
char DAT_004f6760[256][8];                  /* 0x004F6760 */

signed char DAT_004f6f68;                   /* 0x004F6F68 */

/* 0x0048D420 */
unsigned char FUN_0048d420(unsigned char v)
{
    unsigned char r;
    unsigned char i;
    int s;

    r = 0;
    i = 0;
    s = 7;
    do {
        r |= (unsigned char)(((v >> i) & 1) << s);
        i++;
        s--;
    } while (i < 8);
    return r;
}

/* 0x0048D450 */
unsigned char FUN_0048d450(FILE *f)
{
    unsigned char b;

    fread(&f, 1, 1, f);
    b = *(unsigned char *)&f;
    b ^= 0x53;
    return b;
}

/* 0x0048D470 */
void FUN_0048d470(unsigned char b, FILE *f)
{
    fseek(f, 0, 0);
    b ^= 0x53;
    fwrite(&b, 1, 1, f);
}

/* 0x0048D4B0 */
unsigned long FUN_0048d4b0(FILE *f)
{
    fread(&f, 4, 1, f);
    return (unsigned long)f ^ 0x54555657UL;
}

/* 0x0048D4D0 */
void FUN_0048d4d0(unsigned long v, FILE *f)
{
    v ^= 0x54555657UL;
    fwrite(&v, 4, 1, f);
}

/* 0x0048D500 */
int FUN_0048d500(FILE *f)
{
    int c;

    c = getc(f);
    if (c != EOF)
        DAT_004b9c40++;
    return c;
}

/* 0x0048D530 */
int FUN_0048d530(int v, FILE *f)
{
    int r;

    r = (unsigned char)FUN_0048d420(DAT_004a6798++) ^ 0xb9;
    DAT_004f6f68 += (char)v;
    r ^= v;
    DAT_004b9c3c++;
    return putc(r, f);
}

/* 0x0048D5A0 */
int FUN_0048d5a0(FILE *f)
{
    int v;
    int r;

    v = getc(f);
    r = v;
    if (v != EOF) {
        r = (unsigned char)FUN_0048d420(DAT_004a6798++) ^ 0xb9;
        r ^= v;
        DAT_004f6f68 -= (char)r;
        DAT_004b9c3c++;
    }
    return r;
}

/* 0x0048D610 */
int FUN_0048d610(int c, FILE *f)
{
    DAT_004b9c40--;
    if (DAT_004b9c40 < 0)
        DAT_004b9c38 = 1;
    return putc(c, f);
}

/* 0x0048D660 */
void FUN_0048d660(void)
{
    int i;
    int j;

    for (i = 0; i < 256; i++)
        for (j = 0; j < 8; j++)
            DAT_004f6760[i][j] = (char)i;
    DAT_004b9c40 = 0;
    DAT_004b9c3c = 0;
    DAT_004b9c38 = 0;
    DAT_004a6798 = 0x57;
}

char DAT_004f6f60[8];                       /* 0x004F6F60 */

/* 0x0048D6B0 */
void FUN_0048d6b0(FILE *in, FILE *out)
{
    int best_idx;
    int n;
    int cnt;
    int c;
    int best_score;
    int idx;
    int score;
    int k;
    char *p;
    char *q;
    int blk;
    int lo;
    int hi;
    int bit;
    int mask;

    best_idx = 0;
    FUN_0048d660();
    DAT_004f6f68 = 0;
    FUN_0048d470(0, out);
    DAT_004b9c40 = 0;
    FUN_0048d4d0(0, out);
    while (!DAT_004b9c38) {
        cnt = 0;
        n = 8;
        while (cnt < 8) {
            c = FUN_0048d500(in);
            if (c == EOF) {
                n = cnt;
                break;
            }
            DAT_004f6f60[cnt] = (char)c;
            cnt++;
        }
        if (n == 0) {
            DAT_004b9c38 = 1;
            continue;
        }
        best_score = -1;
        idx = 0;
        p = &DAT_004f6760[0][0];
        do {
            score = 0;
            k = 0;
            q = p;
            if (0 < n) {
                do {
                    if (*q == DAT_004f6f60[k])
                        score++;
                    k++;
                    q++;
                } while (k < n);
            }
            if (best_score < score && (best_score = score, best_idx = idx, score == n))
                break;
            p += 8;
            idx++;
        } while ((int)p < (int)&DAT_004f6760[256][0]);
        FUN_0048d530(best_idx, out);
        for (blk = 0; blk < 1; blk++) {
            lo = blk * 8;
            hi = lo + 8;
            mask = 0;
            bit = 1;
            for (k = lo; k < hi && k < n; k++) {
                if (DAT_004f6760[best_idx][k] != DAT_004f6f60[k])
                    mask += bit;
                bit *= 2;
            }
            FUN_0048d530(mask, out);
            for (k = lo; k < hi; k++) {
                if (mask % 2 == 1)
                    FUN_0048d530((int)DAT_004f6f60[k], out);
                mask /= 2;
            }
            if (n < 8) {
                FUN_0048d530(n, out);
                DAT_004b9c38 = 1;
            } else {
                for (k = 0; k < 8; k++)
                    DAT_004f6760[best_idx][k] = DAT_004f6f60[k];
            }
        }
    }
    FUN_0048d470(DAT_004f6f68, out);
    FUN_0048d4d0(DAT_004b9c40, out);
}

/* 0x0048D890 */
void FUN_0048d890(FILE *in, FILE *out)
{
    int idx;
    int i;
    int hi;
    int mask;

    idx = -1;
    mask = 0;
    FUN_0048d660();
    DAT_004f6f68 = (signed char)FUN_0048d450(in);
    DAT_004b9c40 = (int)FUN_0048d4b0(in);
    while (!DAT_004b9c38) {
        if (idx == -1) {
            idx = FUN_0048d5a0(in);
            if (idx == -1)
                DAT_004b9c38 = 1;
            else
                mask = FUN_0048d5a0(in);
        } else {
            idx = FUN_0048d5a0(in);
            if (idx == -1) {
                for (i = 0; i < 8; i++)
                    FUN_0048d610(DAT_004f6f60[i], out);
                DAT_004b9c38 = 1;
            } else {
                mask = FUN_0048d5a0(in);
                if (mask == -1) {
                    for (i = 0; i < idx; i++)
                        FUN_0048d610(DAT_004f6f60[i], out);
                    DAT_004b9c38 = 1;
                } else {
                    for (i = 0; i < 8; i++)
                        FUN_0048d610(DAT_004f6f60[i], out);
                }
            }
        }
        if (DAT_004b9c38)
            break;
        i = 0;
        do {
            if (0 < i)
                mask = FUN_0048d5a0(in);
            hi = i + 8;
            for (; i < hi; i++) {
                if (mask % 2 == 1)
                    DAT_004f6760[idx][i] = (char)FUN_0048d5a0(in);
                DAT_004f6f60[i] = DAT_004f6760[idx][i];
                mask /= 2;
            }
        } while (i < 8);
    }
    if (DAT_004b9c40 == 0) {
        if (DAT_004f6f68 != 0) {
            ERM_fn_vClearLastError(0);
            ERM_fn_vUpdateLastError(0xb, DAT_004a6784, 0, 9, -1, 0xff, 0xff, 0);
        }
    } else {
        ERM_fn_vClearLastError(0);
        ERM_fn_vUpdateLastError(0xb, DAT_004a6784, 0, 10, -1, 0xff, 0xff, 0);
    }
}

/* 0x0048DA90 */
BIT_FILE *OpenOutputBitFile(char *name)
{
    BIT_FILE *bit_file;
    FILE *f;

    bit_file = NULL;
    f = fopen(name, "wb");
    if (f != NULL) {
        bit_file = (BIT_FILE *)calloc(1, sizeof(BIT_FILE));
        if (bit_file != NULL) {
            bit_file->file = f;
            bit_file->rack = 0;
            bit_file->mask = 0x80;
            bit_file->pacifier_counter = 0;
        }
    }
    return bit_file;
}

/* 0x0048DAE0 */
BIT_FILE *OpenInputBitFile(char *name)
{
    BIT_FILE *bit_file;
    FILE *f;

    bit_file = NULL;
    f = fopen(name, "rb");
    if (f != NULL) {
        bit_file = (BIT_FILE *)calloc(1, sizeof(BIT_FILE));
        if (bit_file != NULL) {
            bit_file->file = f;
            bit_file->rack = 0;
            bit_file->mask = 0x80;
            bit_file->pacifier_counter = 0;
        }
    }
    return bit_file;
}

/* 0x0048DB30 */
void CloseOutputBitFile(BIT_FILE *bit_file)
{
    if (bit_file->mask != 0x80)
        if (putc(bit_file->rack, bit_file->file) != bit_file->rack) {
            ERM_fn_vClearLastError(0);
            ERM_fn_vUpdateLastError(0xb, DAT_004a6784, 0, 4, -1, 0xff, 0xff, 0);
        }
    fclose(bit_file->file);
    free((char *)bit_file);
}

/* 0x0048DBC0 */
void CloseInputBitFile(BIT_FILE *bit_file)
{
    fclose(bit_file->file);
    free((char *)bit_file);
}

/* 0x0048DBE0 */
void OutputBit(BIT_FILE *bit_file, int bit)
{
    if (bit)
        bit_file->rack |= bit_file->mask;
    bit_file->mask >>= 1;
    if (bit_file->mask == 0) {
        if (putc(bit_file->rack, bit_file->file) != bit_file->rack) {
            ERM_fn_vClearLastError(0);
            ERM_fn_vUpdateLastError(0xb, DAT_004a6784, 0, 5, -1, 0xff, 0xff, 0);
        }
        bit_file->rack = 0;
        bit_file->mask = 0x80;
    }
}

/* 0x0048DC80 */
void OutputBits(BIT_FILE *bit_file, unsigned long code, int count)
{
    unsigned long mask;

    mask = 1L << (count - 1);
    while (mask != 0) {
        if (mask & code)
            bit_file->rack |= bit_file->mask;
        bit_file->mask >>= 1;
        if (bit_file->mask == 0) {
            if (putc(bit_file->rack, bit_file->file) != bit_file->rack) {
                ERM_fn_vClearLastError(0);
                ERM_fn_vUpdateLastError(0xb, DAT_004a6784, 0, 6, -1, 0xff, 0xff, 0);
            }
            bit_file->rack = 0;
            bit_file->mask = 0x80;
        }
        mask >>= 1;
    }
}

/* 0x0048DD40 */
int InputBit(BIT_FILE *bit_file)
{
    int value;

    if (bit_file->mask == 0x80) {
        bit_file->rack = getc(bit_file->file);
        if (bit_file->rack == EOF) {
            ERM_fn_vClearLastError(0);
            ERM_fn_vUpdateLastError(0xb, DAT_004a6784, 0, 7, -1, 0xff, 0xff, 0);
        }
    }
    value = bit_file->rack & bit_file->mask;
    bit_file->mask >>= 1;
    if (bit_file->mask == 0)
        bit_file->mask = 0x80;
    return (value ? 1 : 0);
}

/* 0x0048DDD0 */
unsigned long InputBits(BIT_FILE *bit_file, int bit_count)
{
    unsigned long mask;
    unsigned long return_value;

    mask = 1L << (bit_count - 1);
    return_value = 0;
    while (mask != 0) {
        if (bit_file->mask == 0x80) {
            bit_file->rack = getc(bit_file->file);
            if (bit_file->rack == EOF) {
                ERM_fn_vClearLastError(0);
                ERM_fn_vUpdateLastError(0xb, DAT_004a6784, 0, 8, -1, 0xff, 0xff, 0);
            }
        }
        if (bit_file->rack & bit_file->mask)
            return_value |= mask;
        mask >>= 1;
        bit_file->mask >>= 1;
        if (bit_file->mask == 0)
            bit_file->mask = 0x80;
    }
    return return_value;
}

/* 0x0048DE80 */
void InitTree(int r)
{
    tree[TREE_ROOT].larger_child = r;
    tree[r].parent = TREE_ROOT;
    tree[r].larger_child = UNUSED;
    tree[r].smaller_child = UNUSED;
}

/* 0x0048DEB0 */
void ContractNode(int old_node, int new_node)
{
    tree[new_node].parent = tree[old_node].parent;
    if (tree[tree[old_node].parent].larger_child == old_node)
        tree[tree[old_node].parent].larger_child = new_node;
    else
        tree[tree[old_node].parent].smaller_child = new_node;
    tree[old_node].parent = UNUSED;
}

/* 0x0048DF10 */
void ReplaceNode(int old_node, int new_node)
{
    int parent;

    parent = tree[old_node].parent;
    if (tree[parent].smaller_child == old_node)
        tree[parent].smaller_child = new_node;
    else
        tree[parent].larger_child = new_node;
    tree[new_node] = tree[old_node];
    tree[tree[new_node].smaller_child].parent = new_node;
    tree[tree[new_node].larger_child].parent = new_node;
    tree[old_node].parent = UNUSED;
}

/* 0x0048DFA0 */
int FindNextNode(int node)
{
    int next;

    next = tree[node].smaller_child;
    while (tree[next].larger_child != UNUSED)
        next = tree[next].larger_child;
    return next;
}

/* 0x0048DFD0 */
void DeleteString(int p)
{
    int replacement;

    if (tree[p].parent == UNUSED)
        return;
    if (tree[p].larger_child == UNUSED)
        ContractNode(p, tree[p].smaller_child);
    else if (tree[p].smaller_child == UNUSED)
        ContractNode(p, tree[p].larger_child);
    else {
        replacement = FindNextNode(p);
        DeleteString(replacement);
        ReplaceNode(p, replacement);
    }
}

/* 0x0048E040 */
int AddString(int new_node, int *match_position)
{
    int i;
    int test_node;
    int delta;
    int match_length;
    int *child;

    if (new_node == END_OF_STREAM)
        return 0;
    test_node = tree[TREE_ROOT].larger_child;
    match_length = 0;
    for (;;) {
        for (i = 0; i < LOOK_AHEAD_SIZE; i++) {
            delta = window[MOD_WINDOW(new_node + i)] -
                    window[MOD_WINDOW(test_node + i)];
            if (delta != 0)
                break;
        }
        if (i >= match_length) {
            match_length = i;
            *match_position = test_node;
            if (match_length >= LOOK_AHEAD_SIZE) {
                ReplaceNode(test_node, new_node);
                return match_length;
            }
        }
        if (delta >= 0)
            child = &tree[test_node].larger_child;
        else
            child = &tree[test_node].smaller_child;
        if (*child == UNUSED) {
            *child = new_node;
            tree[new_node].parent = test_node;
            tree[new_node].larger_child = UNUSED;
            tree[new_node].smaller_child = UNUSED;
            return match_length;
        }
        test_node = *child;
    }
}

/* 0x0048E120 */
void CompressFile(FILE *input, BIT_FILE *output)
{
    int i;
    int c;
    int look_ahead_bytes;
    int current_position;
    int replace_count;
    int match_length;
    int match_position;

    current_position = 1;
    for (i = 0; i < LOOK_AHEAD_SIZE; i++) {
        if ((c = getc(input)) == EOF)
            break;
        window[current_position + i] = (unsigned char)c;
    }

    look_ahead_bytes = i;
    InitTree(current_position);
    match_length = 0;
    match_position = 0;

    while (look_ahead_bytes > 0) {
        if (match_length > look_ahead_bytes)
            match_length = look_ahead_bytes;

        if (match_length <= BREAK_EVEN) {
            replace_count = 1;
            OutputBit(output, 1);
            OutputBits(output, (unsigned long)window[current_position], 8);
        } else {
            OutputBit(output, 0);
            OutputBits(output, (unsigned long)match_position, INDEX_BIT_COUNT);
            OutputBits(output, (unsigned long)(match_length - (BREAK_EVEN + 1)), LENGTH_BIT_COUNT);
            replace_count = match_length;
        }

        for (i = 0; i < replace_count; i++) {
            DeleteString(MOD_WINDOW(current_position + LOOK_AHEAD_SIZE));

            if ((c = getc(input)) == EOF)
                look_ahead_bytes--;
            else
                window[MOD_WINDOW(current_position + LOOK_AHEAD_SIZE)] = (unsigned char)c;

            current_position = MOD_WINDOW(current_position + 1);

            if (look_ahead_bytes)
                match_length = AddString(current_position, &match_position);
        }
    }
    OutputBit(output, 0);
    OutputBits(output, (unsigned long)END_OF_STREAM, INDEX_BIT_COUNT);
}

/* 0x0048E290 */
void ExpandFile(BIT_FILE *input, FILE *output)
{
    int i;
    int current_position;
    int c;
    int match_length;
    int match_position;

    current_position = 1;
    for (;;) {
        if (InputBit(input)) {
            c = (int)InputBits(input, 8);
            putc(c, output);
            window[current_position] = (unsigned char)c;
            current_position = MOD_WINDOW(current_position + 1);
        } else {
            match_position = (int)InputBits(input, INDEX_BIT_COUNT);
            if (match_position == END_OF_STREAM)
                break;
            match_length = (int)InputBits(input, LENGTH_BIT_COUNT);
            match_length += BREAK_EVEN;
            for (i = 0; i <= match_length; i++) {
                c = window[MOD_WINDOW(match_position + i)];
                putc(c, output);
                window[current_position] = (unsigned char)c;
                current_position = MOD_WINDOW(current_position + 1);
            }
        }
    }
}
