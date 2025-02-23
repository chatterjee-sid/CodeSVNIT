#include<stdio.h>
#include<stdlib.h>
struct vs {
    int vsi;
    float vsf;
    char vsc;
};
union vu {
    int vui;
    float vuf;
    char vuc;
};
int g_int_ui;
int g_int_i = 10;
void main() {
    printf("initialised gloable integer\n");
    printf("g_int_i : %u %x size: %u\n", &g_int_i, &g_int_i, sizeof(g_int_i));
    printf("uninitialised global integer\n");
    printf("g_int_ui : %u %x size: %u\n", &g_int_ui, &g_int_ui, sizeof(g_int_ui));
    char v_char;
    printf("Character\n");
    printf("v_char : %u %x size: %u\n", &v_char, &v_char, sizeof(v_char));
    short int v_sint;
    printf("Short Integer\n");
    printf("v_sint : %u %x size: %u\n", &v_sint, &v_sint, sizeof(v_sint));
    int v_int;
    printf("Integer\n");
    printf("v_int : %u %x size: %u\n", &v_int, &v_int, sizeof(v_int));
    float v_float;
    printf("Float\n");
    printf("v_float : %u %x size: %u\n", &v_float, &v_float, sizeof(v_float));
    long int v_lint;
    printf("Long Integer\n");
    printf("v_lint : %u %x size: %u\n", &v_lint, &v_lint, sizeof(v_lint));
    double v_double;
    printf("Double\n");
    printf("v_double : %u %x size: %u\n", &v_double, &v_double, sizeof(v_double));
    long long int v_llint;
    printf("Long Long Integer\n");
    printf("v_llint : %u %x size: %u\n", &v_llint, &v_llint, sizeof(v_llint));
    long double v_ldouble;
    printf("Long Double\n");
    printf("v_ldouble : %u %x size: %u\n", &v_ldouble, &v_ldouble, sizeof(v_ldouble));
    int v_intarr[5];
    printf("1D Integer Array (5 elements)\n");
    printf("v_intarr : %u %x size: %u\n", &v_intarr, &v_intarr, sizeof(v_intarr));
    printf("v_intarr[0] : %u %x\n", &v_intarr[0], &v_intarr[0]);
    printf("v_intarr[1] : %u %x\n", &v_intarr[1], &v_intarr[1]);
    printf("v_intarr[4] : %u %x\n", &v_intarr[4], &v_intarr[4]);
    int v_intarr2[5][5];
    printf("2D Integer Array (5 x 5 elements)\n");
    printf("v_intarr2 : %u %x size: %u\n", &v_intarr2, &v_intarr2, sizeof(v_intarr2));
    printf("v_intarr2[0] : %u %x size:
        % u\n",&v_intarr2[0],&v_intarr2[0],sizeof(v_intarr2[0]));
        printf("v_intarr2[0][0] : %u %x\n", &v_intarr2[0][0], &v_intarr2[0][0]);
    printf("v_intarr2[0][1] : %u %x\n", &v_intarr2[0][1], &v_intarr2[0][1]);
    printf("v_intarr2[0][4] : %u %x\n", &v_intarr2[0][4], &v_intarr2[0][4]);
    printf("v_intarr2[1] : %u %x\n", &v_intarr2[1], &v_intarr2[1]);
    printf("v_intarr2[1][0] : %u %x\n", &v_intarr2[1][0], &v_intarr2[1][0]);
    printf("v_intarr2[1][1] : %u %x\n", &v_intarr2[1][1], &v_intarr2[1][1]);
    printf("v_intarr2[1][4] : %u %x\n", &v_intarr2[1][4], &v_intarr2[1][4]);
    printf("v_intarr2[4] : %u %x\n", &v_intarr2[4], &v_intarr2[4]);
    printf("v_intarr2[4][0] : %u %x\n", &v_intarr2[4][0], &v_intarr2[4][0]);
    printf("v_intarr2[4][1] : %u %x\n", &v_intarr2[4][1], &v_intarr2[4][1]);
    printf("v_intarr2[4][4] : %u %x\n", &v_intarr2[4][4], &v_intarr2[4][4]);
    struct vs v_struct;
    printf("Structure (1 int, 1 float, 1 char)\n");
    printf("v_struct : %u %x size: %u\n", &v_struct, &v_struct, sizeof(v_struct));
    printf("v_struct.vsi : %u %x size:
        % u\n",&v_struct.vsi,&v_struct.vsi,sizeof(v_struct.vsi));
        printf("v_struct.vsf : %u %x size:
            % u\n",&v_struct.vsf,&v_struct.vsf,sizeof(v_struct.vsf));
            printf("v_struct.vsc : %u %x size:
                % u\n",&v_struct.vsc,&v_struct.vsc,sizeof(v_struct.vsc));
                union vu v_union;
    printf("Union (1 int, 1 float, 1 char)\n");
    printf("v_union : %u %x size: %u\n", &v_union, &v_union, sizeof(v_union));
    printf("v_union.vui : %u %x size:
        % u\n",&v_union.vui,&v_union.vui,sizeof(v_union.vui));
        printf("v_union.vuf : %u %x size:
            % u\n",&v_union.vuf,&v_union.vuf,sizeof(v_union.vuf));
            printf("v_union.vuc : %u %x size:
                % u\n",&v_union.vuc,&v_union.vuc,sizeof(v_union.vuc));
                int* p_dma = (int*)malloc(sizeof(int) * 20);
    printf("Dynamically allocated integer space\n");
    printf("p_dma : %u %x size: %u\n", &p_dma, &p_dma, sizeof(p_dma));
    printf("*p_dma : %u %x size: %u\n", p_dma, p_dma, sizeof(*(p_dma + 1)));
    printf("*(p_dma+1) : %u %x size: %u\n", p_dma + 1, p_dma + 1);
    free(p_dma);
}