#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define um tipo Byte de 8 bits, para ler os dados binários do cartão
typedef uint8_t Byte;

// Buffer de 512 bytes para ler cada bloco do cartão
Byte Buffer[512];

// Variável para armazenar quantos bytes foram lidos no último fread
size_t bytesRead;

// Contador de arquivos JPEG encontrados
int JPEG_count = 0;

// String para armazenar o nome do arquivo JPEG atual (ex: 000.jpg)
char filename[8];

// Ponteiro para o arquivo JPEG que estamos escrevendo
FILE *img;

int main(int argc, char *argv[])
{
    // Verifica se o programa recebeu exatamente um argumento (nome do arquivo de entrada)
    if (argc != 2)
    {
        printf("Uso: ./recuperar imagem\n");
        return 1;
    }

    // Abre o arquivo de entrada (cartão) para leitura
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    // Loop principal: lê blocos de 512 bytes até o fim do arquivo
    while ((bytesRead = fread(Buffer, sizeof(Byte), 512, file)) > 0)
    {
        // Verifica se o bloco atual é o início de um JPEG
        if (Buffer[0] == 0xff && Buffer[1] == 0xd8 &&
            Buffer[2] == 0xff && (Buffer[3] & 0xf0) == 0xe0)
        {
            // Se já existe um arquivo JPEG aberto, fecha ele antes de criar um novo
            if (img != NULL)
            {
                fclose(img);
            }

            // Gera o nome do novo arquivo JPEG (ex: 000.jpg, 001.jpg, etc.)
            sprintf(filename, "%03i.jpg", JPEG_count);
            JPEG_count++;

            // Abre o novo arquivo JPEG para escrita
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Erro ao criar o arquivo %s\n", filename);
                fclose(file); // fecha o arquivo de entrada antes de sair
                return 1;
            }
        }

        // Se já temos um arquivo JPEG aberto, escreve o bloco lido nele
        if (img != NULL)
        {
            fwrite(Buffer, sizeof(Byte), bytesRead, img);
        }
    }

    // Fecha o último arquivo JPEG aberto, se houver
    if (img != NULL)
    {
        fclose(img);
    }

    // Fecha o arquivo de entrada
    fclose(file);

    return 0;
}
