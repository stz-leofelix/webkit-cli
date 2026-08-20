#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

// Reset
#define COLOR_RESET   "\033[0m"

// Text Styles
#define STYLE_BOLD    "\033[1m"
#define STYLE_DIM     "\033[2m"
#define STYLE_ITALIC  "\033[3m"
#define STYLE_UNDER   "\033[4m"

// Normal Colors
#define COLOR_BLACK   "\033[30m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"

// Bold Colors
#define BOLD_BLACK   "\033[1;30m"
#define BOLD_RED     "\033[1;31m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_YELLOW  "\033[1;33m"
#define BOLD_BLUE    "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN    "\033[1;36m"
#define BOLD_WHITE   "\033[1;37m"

// Program Informations
#define PROGRAM_VERSION "0.5.0"
#define PROGRAM_PRODUCTION_CHANNEL "ALPHA RELEASE"

// Helper functions
void error(char *type, char *message);

// Function Command
void cmd_help_all(void);
void cmd_version(void);
void cmd_init(void);
void cmd_init_help(void);

// Dispatch Table
typedef struct {
    char *name;
    void (*func)(void);
} CMD;

CMD DISPATCH[] = {
    {"help", cmd_help_all},
    {"-h", cmd_help_all},
    {"--help", cmd_help_all},

    {"init", cmd_init},
    {"init -h", cmd_init_help},
    {"init --help", cmd_init_help},

    {"version", cmd_version},
    {"-v", cmd_version},
    {"--version", cmd_version},
};

int cmdcount = 9;

int main(int argc, char *argv[])
{
    // Force help function call if no arguments provided
    if (argc == 1) {
        cmd_help_all();
        printf("\n");
        return 404;
    }

    // Get the formatted full string argument of program input
    int total_length = 0;
    for (int i = 1; i < argc; i++)
    {
        total_length += strlen(argv[i]);
    }
    char *input = malloc(sizeof(char) * total_length + 2);
    *input = '\0';
    for (int i = 1; i < argc; i++)
    {
        strcat(input, argv[i]);
        if (i < argc - 1) 
            strcat(input, " ");
    }

    // Check if the input exists in DISPATCH then call the corresponding function if it do exist
    for (int i = 0; i < cmdcount; i++) {
        if (strcmp(DISPATCH[i].name, input) == 0) {
            DISPATCH[i].func();
            printf("\n");
            free(input);
            return 0;
            break;
        }
    }

    // No commands found
    printf(BOLD_RED"CommandError: "COLOR_RESET COLOR_YELLOW"'%s\'"COLOR_RESET" is not an valid webkit command\n", argv[1]);
    printf("\n");
    free(input);
    return 0;
}

// HELPER error
void error(char *type, char *message) {
    if (strcmp(type, "command"))
        printf(BOLD_RED"CommandError: "COLOR_RESET"%s", message);
    return;
}

// CMD init help
void cmd_init_help(void) {
    printf(
        BOLD_BLUE "Usage: " COLOR_RESET "webkit init [type] [options]\n"
        "If type is not given then it's automatically set to "BOLD_BLUE"standard"COLOR_RESET"\n\n"
        BOLD_BLUE "Types:\n" COLOR_RESET
        "  high                  Initialize higher standard webkit repo (Suitable for big projects and websites)\n"
        "  standard              Initialize standard webkit repo\n"
        "  starter               Initialize a small standard webkit repo (Suitable for small sites or projects)\n"
        "  lite                  Initialize lite standard webkit repo (Suitable for very small tests or simple one page sites)\n\n"
        BOLD_BLUE "Options:\n" COLOR_RESET
        "  -h, --help            Display instruction on usage\n"
        "  -f, --force           Delete all files and initalize a repo\n"
        "  -m, --migrate         Migrate already existing files into the initialized repo\n"
        "  -q, --quiet           Suppress all stdout messages\n\n"
        BOLD_BLUE "Examples:\n" COLOR_RESET
        "  $ webkit init\n"
        "  $ webkit init starter\n"
        "  $ webkit init lite -h\n"
        "  $ webkit init high --migrate\n"
    );
}

// CMD init
void cmd_init(void)
{
    // CREATE HTML & IMPORT BIOLERPLATE | index.html
    FILE *index_html = fopen("index.html", "w");
    if (index_html == NULL)
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create file index.html\n");
    else {
        fprintf(index_html,
            "<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<head>\n"
            "    <meta charset=\"UTF-8\">\n"
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
            "    <title>WEBKIT Standard HTML</title>\n"
            "    <link rel=\"stylesheet\" href=\"./css/reset.css\"> <!-- WEBKIT css/reset.css -->\n"
            "    <link rel=\"stylesheet\" href=\"./css/style.css\"> <!-- WEBKIT css/style.css -->\n"
            "</head>\n"
            "<body>\n"
            "    <!-- WEBKIT HTML content here -->\n"
            "\n"
            "    <script src=\"./js/script.js\"></script> <!-- WEBKIT js/script.js -->\n"
            "</body>\n"
            "</html>\n"
        );
        fclose(index_html);
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created file index.html\n");
    }

    // CREATE DIRECTORIES | css/ js/ assets/ assets/images assets/icons assets/fonts
    if (_mkdir("css") == 0) {
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created dir css/\n");
    } else {
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create dir css/\n");
    }

    if (_mkdir("js") == 0) {
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created dir js/\n");
    } else {
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create dir js/\n");
    }

    if (_mkdir("assets") == 0) {
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created dir assets/\n");
    } else {
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create dir assets/\n");
    }

    if (_mkdir("assets/images") == 0) {
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created dir assets/images/\n");
    } else {
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create dir assets/images/\n");
    }

    if (_mkdir("assets/icons") == 0) {
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created dir assets/icons/\n");
    } else {
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create dir assets/icons/\n");
    }

    if (_mkdir("assets/fonts") == 0) {
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created dir assets/fonts/\n");
    } else {
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create dir assets/fonts/\n");
    }

    // CREATE STYLE.CSS IN CSS | css/style.css
    FILE *style_css = fopen("css/style.css", "w");
    if (style_css == NULL)
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create file css/style.css");
    else {
        fprintf(style_css, "/* WEBKIT CSS content here */");
        fclose(style_css);
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created file css/style.css\n");
    }

    // CREATE RESET.CSS IN CSS | css/reset.css
    FILE *reset_css = fopen("css/reset.css", "w");
    if (reset_css == NULL)
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create file css/reset.css");
    else {
        fprintf(reset_css,
            "/* WEBKIT Standard css/reset.css */\n"
            "/* http://meyerweb.com/eric/tools/css/reset/ \n"
            "   v2.0 | 20110126\n"
            "   License: none (public domain)\n"
            "*/\n\n"
            "html, body, div, span, applet, object, iframe,\n"
            "h1, h2, h3, h4, h5, h6, p, blockquote, pre,\n"
            "a, abbr, acronym, address, big, cite, code,\n"
            "del, dfn, em, img, ins, kbd, q, s, samp,\n"
            "small, strike, strong, sub, sup, tt, var,\n"
            "b, u, i, center,\n"
            "dl, dt, dd, ol, ul, li,\n"
            "fieldset, form, label, legend,\n"
            "table, caption, tbody, tfoot, thead, tr, th, td,\n"
            "article, aside, canvas, details, embed, \n"
            "figure, figcaption, footer, header, hgroup, \n"
            "menu, nav, output, ruby, section, summary,\n"
            "time, mark, audio, video {\n"
            "\tmargin: 0;\n"
            "\tpadding: 0;\n"
            "\tborder: 0;\n"
            "\tfont-size: 100%%;\n"
            "\tfont: inherit;\n"
            "\tvertical-align: baseline;\n"
            "}\n"
            "/* HTML5 display-role reset for older browsers */\n"
            "article, aside, details, figcaption, figure, \n"
            "footer, header, hgroup, menu, nav, section {\n"
            "\tdisplay: block;\n"
            "}\n"
            "body {\n"
            "\tline-height: 1;\n"
            "}\n"
            "ol, ul {\n"
            "\tlist-style: none;\n"
            "}\n"
            "blockquote, q {\n"
            "\tquotes: none;\n"
            "}\n"
            "blockquote:before, blockquote:after,\n"
            "q:before, q:after {\n"
            "\tcontent: '';\n"
            "\tcontent: none;\n"
            "}\n"
            "table {\n"
            "\tborder-collapse: collapse;\n"
            "\tborder-spacing: 0;\n"
            "}\n"
        );
        fclose(reset_css);
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created file css/reset.css\n");
    }

    // CREATE SCRIPT.JS IN JS | js/script.js
    FILE *script_js = fopen("js/script.js", "w");
    if (script_js == NULL)
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create file js/script.js");
    else {
        fprintf(script_js, "// WEBKIT javascript content here");
        fclose(script_js);
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created file js/script.js\n");
    }

    // CREATE README.MD | README.md
    FILE *readme_md = fopen("README.md", "w");
    if (readme_md == NULL)
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create file README.md");
    else {
        fprintf(readme_md, "<!-- WEBKIT README content here -->");
        fclose(readme_md);
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created file README.md\n");
    }

    printf("\nInitialized " BOLD_BLUE "STANDARD WEBKIT" COLOR_RESET " repository\n\n");
}

// CMD init high


void cmd_help_all(void) {
    printf(
        BOLD_BLUE "WEBKIT "PROGRAM_VERSION" ("PROGRAM_PRODUCTION_CHANNEL")\n\n" COLOR_RESET
        BOLD_BLUE "Usage: " COLOR_RESET "webkit <command> [options]\n\n"
        BOLD_BLUE "Commands:\n" COLOR_RESET
        "  init                  Initialize standard webkit repository\n"
        "  help                  Display commands and instructions on usage\n\n" 
        BOLD_BLUE "Options:\n" COLOR_RESET
        "  -v, --version         Outputs the current version\n"
        "  -h, --help            Display commands and instruction on usage\n\n"
        BOLD_BLUE "Examples:\n" COLOR_RESET
        "  $ webkit init\n"
        "  $ webkit init --help\n"
    );
}

void cmd_version(void) {
    printf("WEBKIT VERSION "BOLD_BLUE "("PROGRAM_VERSION ")"COLOR_RESET "\n\n");
    printf("Version: "PROGRAM_VERSION "\n");
    printf("Production Channel: "PROGRAM_PRODUCTION_CHANNEL "\n");
}