grammar scene;
// Generare runtime manually:
// antlr4 -Dlanguage=Cpp -no-listener -visitor -o antlr4-runtime scene.g4

// Parser Rules
scene: paramlist object+ resolution EOF;

paramlist: param+;

param:
	SHININESS NUMBER
	| ANTIALIAS NUMBER
	| BACKGROUND NUMBER NUMBER NUMBER
	| MAXDEPTH NUMBER
    ;

object:
    light
    | sphere
    | quad
    ;

light:
    LIGHT
    position
    diffuse
    specular
    ;

sphere:
    SPHERE
    position radius
    diffuse
    specular
    ambient
    (MIRROR | DIFFUSE)
    ;

quad:
    QUAD
    position
    position
    position
    position
    diffuse
    specular
    ambient
    (MIRROR | DIFFUSE)
    ;

radius:
    RADIUS NUMBER
    ;

position:
    POS NUMBER NUMBER NUMBER
    ;

diffuse:
    DIFF NUMBER NUMBER NUMBER
    ;

specular:
    SPEC NUMBER NUMBER NUMBER
    ;

ambient:
    AMB NUMBER NUMBER NUMBER
    ;

resolution: RESOLUTION NUMBER NUMBER; 

// Lexer Rules

NUMBER: '-'? [0-9]+ ('.' [0-9]+)?;
SHININESS: 'SHININESS';
ANTIALIAS: 'ANTIALIAS';
BACKGROUND: 'BACKGROUND';
MAXDEPTH: 'MAXDEPTH';
RESOLUTION: 'RESOLUTION';
LIGHT: 'LIGHT';
SPHERE: 'SPHERE';
QUAD: 'QUAD';
POS: 'POS';
DIFF: 'DIFF';
SPEC: 'SPEC';
AMB: 'AMB';
RADIUS: 'RADIUS';
MIRROR: 'MIRROR';
DIFFUSE: 'DIFFUSE';

NEWLINE: ('\r'? '\n' | '\r')+ -> skip;
TAB: ('\t' | '        ' | '    ') -> skip;
COMMENT: '//' .*? NEWLINE -> skip;
WHITESPACE: ' ' -> skip;