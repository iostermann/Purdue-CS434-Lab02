
// Generated from scene.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  sceneLexer : public antlr4::Lexer {
public:
  enum {
    NUMBER = 1, SHININESS = 2, ANTIALIAS = 3, BACKGROUND = 4, MAXDEPTH = 5, 
    RESOLUTION = 6, LIGHT = 7, SPHERE = 8, QUAD = 9, POS = 10, DIFF = 11, 
    SPEC = 12, AMB = 13, RADIUS = 14, MIRROR = 15, DIFFUSE = 16, NEWLINE = 17, 
    TAB = 18, COMMENT = 19, WHITESPACE = 20
  };

  explicit sceneLexer(antlr4::CharStream *input);
  ~sceneLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

