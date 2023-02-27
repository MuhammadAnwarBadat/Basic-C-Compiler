#include <fstream>
#include <iostream>
#include <string>

#include "code_generator.h"
#include "lexer.h"
#include "parser.h"
#include "semantic_analyzer.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Error: no input file specified" << std::endl;
    return 1;
  }

  // Open the input file
  std::ifstream input(argv[1]);
  if (!input.good()) {
    std::cerr << "Error: unable to open input file" << std::endl;
    return 1;
  }

  // Create the lexer and parser
  Lexer lexer(input);
  Parser parser(lexer);

  // Parse the program
  Program* program = parser.ParseProgram();
  if (parser.HasError()) {
    std::cerr << "Error: syntax errors detected" << std::endl;
    return 1;
  }

  // Perform semantic analysis
  SemanticAnalyzer analyzer(lexer);
  analyzer.Analyze(program);

  // Generate code
  CodeGenerator generator;
  generator.Generate(program->GetBlock());

  // Output the generated code
  for (int i : generator.GetCode()) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
