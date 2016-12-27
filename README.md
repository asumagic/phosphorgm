# PhosphorGM

The Phosphor open-source GameMaker:Studio toolchain. It is meant to be a simple toolchain built from scratch, fully independently from GM:S.

PhosphorGM is a work in progress. It is not yet possible to generate bytecode or any sort of directly interpretable structure (for now).

Done list:

- Tokenize the source (mostly done)

TODO:

- Parse the tokenized source into an AST (under work)
- Verify the AST
- Generate bytecode or interprete the generated AST directly
- Parse GM:S projects and resources
- Implement warnings and static program analysis; refine compile errors
