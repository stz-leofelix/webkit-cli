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
#define PROGRAM_VERSION "0.2.1"
#define PROGRAM_PRODUCTION_CHANNEL "ALPHA RELEASE"

// Function Command standard
void cmds_help_all(void);

// Function Command
void cmd_init(void);

int main(int argc, char *argv[])
{
    printf("\n");
    // Check if user gives no argument or ask for help
    if (argc == 1 || argc ==  2 && strcmp(argv[1], "help") || argc ==  2 && strcmp(argv[1], "-h") || argc ==  2 && strcmp(argv[1], "--help"))
    {
        cmds_help_all();
        return 0;
    }

    // Initialize standard repository | init
    if (strcmp(argv[1], "init") == 0 && argc == 2)
    {
        cmd_init();
        return 0;
    }
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
        fclose(style_css);
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created file css/style.css\n");
    }

    // CREATE RESET.CSS IN CSS | css/reset.css
    FILE *reset_css = fopen("css/reset.css", "w");
    if (reset_css == NULL)
        printf(COLOR_RED "Failure: " COLOR_RESET "Unable to create file css/reset.css");
    else {
        fprintf(reset_css,
            "/* WEBKIT standard css/reset.css */\n"
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
        fclose(script_js);
        printf(COLOR_GREEN "Success: " COLOR_RESET "Created file js/script.js\n");
    }

    printf("\nInitialized " BOLD_BLUE "STANDARD WEBKIT" COLOR_RESET " repository\n\n");

}

void cmds_help_all(void) {
    printf(
        BOLD_CYAN "WEBKIT "PROGRAM_VERSION" ("PROGRAM_PRODUCTION_CHANNEL")\n" COLOR_RESET
        COLOR_BLACK "A minimal repo generator tool for Web Development Currently only designed for vanilla projects without frameworks.\n\n" COLOR_RESET
        BOLD_BLUE "Usage: " COLOR_RESET "webkit <command> "COLOR_BLACK"[options]\n\n" COLOR_RESET
        BOLD_BLUE "Commands:\n" COLOR_RESET
        "  init                  Initialize standard webkit repository\n"
        "  help                  Display commands and instructions on usage\n\n"
        BOLD_BLUE "Types:\n" COLOR_RESET
        "  high                  Initialize higher standard webkit repo (Suitable for big projects and websites)\n"
        "  starter               Initialize a small standard webkit repo (Suitable for small sites or projects)\n\n"
        BOLD_BLUE "Options:\n" COLOR_RESET
        "  -v, --version         Outputs the current version\n"
        "  -h, --help            Display commands and instruction on usage\n"
        "  -f, --force           Delete all files and initalize a repo\n"
        "  -m, --migrate         Migrate already existing files into the initialized repo\n"
        "  -q, --quiet           Suppress all stdout messages\n\n"
        BOLD_BLUE "Examples:\n" COLOR_RESET
        BOLD_BLACK"  $ "COLOR_RESET"webkit init\n"
        BOLD_BLACK"  $ "COLOR_RESET"webkit init --force\n"
        BOLD_BLACK"  $ "COLOR_RESET"webkit --help\n\n"
    );
}