#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define ALIVE '*'
#define DEAD  ' '

// Create a new grid for the simulation
static bool **new_canvas(size_t N, size_t M)
{
    bool **canvas = malloc(N*sizeof(bool*));
    for (size_t i = 0; i < N; i++) {
        canvas[i] = malloc(M*sizeof(bool));
        for (size_t j = 0; j < N; j++) {
            canvas[i][j] = 0;
        }
    }
    return canvas;
}

// Our grid has a toroidal topology with wraparound
static int wrap(int i, int N)
{
    int r = i % N;
    if (r < 0) { r = r + N; }
    return r;
}

typedef struct{
    size_t capacity;
    size_t length;
    char *buff;
} Buffer;

static void buffer_init(Buffer *buf)
{
    buf->capacity = 1;
    buf->length = 0;
    buf->buff = malloc(1);
}

static void buffer_append(Buffer *buf, char c)
{
    if (buf->length >= buf->capacity) {
        buf->capacity *= 2;
        buf->buff = realloc(buf->buff, buf->capacity);
    }
    buf->buff[buf->length++] = c;
}

static void buffer_free(Buffer *buf)
{
    free(buf->buff);
}

// Print the grid to stdout
void draw(size_t N, size_t M, bool **cells)
{
    Buffer buf;
    buffer_init(&buf);
    for (size_t i = 0; i < N; i++) {
        buffer_append(&buf, '|');
        for (size_t j = 0; j < M; j++) {
            if (cells[i][j]) {
                buffer_append(&buf, ALIVE);
            } else {
                buffer_append(&buf, DEAD);
            }
        }
        buffer_append(&buf, '|');
        buffer_append(&buf, '\n');
    }
    buffer_append(&buf, '\0');
    printf("%s", buf.buff);
    buffer_free(&buf);
}

// Place a shape in the grid
void spawn(
    size_t N, size_t M, bool **cells,
    size_t Nshape, size_t Mshape, bool **shape,
    size_t top, size_t left)
{
    for (int i = 0; i < Nshape; i++) {
        for (int j = 0; j < Mshape; j++) {
            int ci = wrap(i+top, N);
            int cj = wrap(j+left, M);
            cells[ci][cj] = shape[i][j];
        }
    }
}

// Run one step of the simulation.
void step(size_t N, size_t M, bool **curr_cells, bool **next_cells)
{
    for (int i2 = 0; i2 < N; i2++) {
        int i1 = wrap(i2-1, N);
        int i3 = wrap(i2+1, N);

        for (int j2 = 0; j2 < M; j2++) {
            int j1 = wrap(j2-1, M);
            int j3 = wrap(j2+1, M);

            int c11 = curr_cells[i1][j1];
            int c12 = curr_cells[i1][j2];
            int c13 = curr_cells[i1][j3];

            int c21 = curr_cells[i2][j1];
            int c22 = curr_cells[i2][j2];
            int c23 = curr_cells[i2][j3];

            int c31 = curr_cells[i3][j1];
            int c32 = curr_cells[i3][j2];
            int c33 = curr_cells[i3][j3];

            int sum =
                c11 + c12 + c13 +
                c21 +       c23 +
                c31 + c32 + c33;

            next_cells[i2][j2] =
                (sum == 3 || (sum == 2 && c22 == 1));
        }
    }
}

bool glider1[] = {0,0,1};
bool glider2[] = {1,0,1};
bool glider3[] = {0,1,1};
bool *glider[] = {glider1, glider2, glider3};

#define GLIDER_N 3
#define GLIDER_M 3

void doit(int nsteps)
{
    size_t N = 40;
    size_t M = 80;

    bool **curr_cells = new_canvas(N, M);
    bool **next_cells = new_canvas(N, M);

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 16; j++) {
            int i0 = 5*i + 1 + j*j;
            int j0 = 5*j + 1;
            spawn(
                N, M, curr_cells,
                GLIDER_N, GLIDER_M, glider,
                i0-1, j0-1
            );
        }
    }

    for (int gen = 1; gen <= nsteps; gen++) {
        draw(N, M, curr_cells);
        putchar('\n');

        step(N, M, curr_cells, next_cells);

        bool **tmp;
        tmp = curr_cells;
        curr_cells = next_cells;
        next_cells = tmp;
    }
    draw(N, M, curr_cells);
}

int main()
{
    doit(2000);
    return 0;
}


