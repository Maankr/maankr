#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
// Создание файла
int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
if (fd < 0) {
perror("Ошибка при создании файла");
exit(1);
}
write(fd, "Пример текста в файле", 22);
close(fd);

// Проверка существования файла
if (access("example.txt", F_OK) != -1) {
printf("Файл example.txt существует\n");
} else {
printf("Файл example.txt не существует\n");
}

// Переименование файла
if (rename("example.txt", "renamed_example.txt") != 0) {
perror("Ошибка при переименовании файла");
exit(1);
}

// Удаление файла
if (remove("renamed_example.txt") != 0) {
perror("Ошибка при удалении файла");
exit(1);
}

return 0;
}
