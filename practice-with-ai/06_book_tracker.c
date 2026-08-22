// Type: Practice Struct
// AI-Assited: Codex
struct Book {
    char title[100];
    char author[100];
    int year;
    int isBorrowed;
};

int main(void) {
    struct Book books[3] = {
        { .title = "Time Riders", .author = "Alex Scarrow", .year = 2010, .isBorrowed = 0 },
    };

    return 0;
}
