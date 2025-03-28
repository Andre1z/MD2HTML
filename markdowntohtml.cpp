#include <iostream>
#include <fstream>
#include <regex>
#include <string>

std::string convertMarkdownToHTML(const std::string& markdown) {
    std::string html = markdown;

    // Convert headers
    html = std::regex_replace(html, std::regex("^# (.+)", std::regex_constants::ECMAScript), "<h1>$1</h1>");
    html = std::regex_replace(html, std::regex("^## (.+)", std::regex_constants::ECMAScript), "<h2>$1</h2>");
    html = std::regex_replace(html, std::regex("^### (.+)", std::regex_constants::ECMAScript), "<h3>$1</h3>");

    // Convert bold (**bold**)
    html = std::regex_replace(html, std::regex("\\*\\*(.*?)\\*\\*"), "<b>$1</b>");

    // Convert italic (*italic*)
    html = std::regex_replace(html, std::regex("\\*(.*?)\\*"), "<i>$1</i>");

    // Convert inline code (`code`)
    html = std::regex_replace(html, std::regex("`(.*?)`"), "<code>$1</code>");

    // Convert unordered list (- item)
    html = std::regex_replace(html, std::regex("^- (.+)", std::regex_constants::ECMAScript), "<ul><li>$1</li></ul>");

    return html;
}

int main() {
    std::string markdown, line, output;
    std::ifstream inputFile("input.md");

    if (!inputFile) {
        std::cerr << "Error: Could not open input.md\n";
        return 1;
    }

    while (std::getline(inputFile, line)) {
        markdown += line + "\n";
    }
    inputFile.close();

    output = convertMarkdownToHTML(markdown);

    std::ofstream outputFile("output.html");
    outputFile << output;
    outputFile.close();

    std::cout << "Conversion complete! Check output.html\n";
    return 0;
}
