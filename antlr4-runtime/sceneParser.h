
// Generated from scene.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  sceneParser : public antlr4::Parser {
public:
  enum {
    NUMBER = 1, SHININESS = 2, ANTIALIAS = 3, BACKGROUND = 4, MAXDEPTH = 5, 
    RESOLUTION = 6, LIGHT = 7, SPHERE = 8, QUAD = 9, POS = 10, DIFF = 11, 
    SPEC = 12, AMB = 13, RADIUS = 14, MIRROR = 15, DIFFUSE = 16, NEWLINE = 17, 
    TAB = 18, COMMENT = 19, WHITESPACE = 20
  };

  enum {
    RuleScene = 0, RuleParamlist = 1, RuleParam = 2, RuleObject = 3, RuleLight = 4, 
    RuleSphere = 5, RuleQuad = 6, RuleRadius = 7, RulePosition = 8, RuleDiffuse = 9, 
    RuleSpecular = 10, RuleAmbient = 11, RuleResolution = 12
  };

  explicit sceneParser(antlr4::TokenStream *input);
  ~sceneParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class SceneContext;
  class ParamlistContext;
  class ParamContext;
  class ObjectContext;
  class LightContext;
  class SphereContext;
  class QuadContext;
  class RadiusContext;
  class PositionContext;
  class DiffuseContext;
  class SpecularContext;
  class AmbientContext;
  class ResolutionContext; 

  class  SceneContext : public antlr4::ParserRuleContext {
  public:
    SceneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamlistContext *paramlist();
    ResolutionContext *resolution();
    antlr4::tree::TerminalNode *EOF();
    std::vector<ObjectContext *> object();
    ObjectContext* object(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SceneContext* scene();

  class  ParamlistContext : public antlr4::ParserRuleContext {
  public:
    ParamlistContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamlistContext* paramlist();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHININESS();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *ANTIALIAS();
    antlr4::tree::TerminalNode *BACKGROUND();
    antlr4::tree::TerminalNode *MAXDEPTH();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  ObjectContext : public antlr4::ParserRuleContext {
  public:
    ObjectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LightContext *light();
    SphereContext *sphere();
    QuadContext *quad();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectContext* object();

  class  LightContext : public antlr4::ParserRuleContext {
  public:
    LightContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIGHT();
    PositionContext *position();
    DiffuseContext *diffuse();
    SpecularContext *specular();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LightContext* light();

  class  SphereContext : public antlr4::ParserRuleContext {
  public:
    SphereContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SPHERE();
    PositionContext *position();
    RadiusContext *radius();
    DiffuseContext *diffuse();
    SpecularContext *specular();
    AmbientContext *ambient();
    antlr4::tree::TerminalNode *MIRROR();
    antlr4::tree::TerminalNode *DIFFUSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SphereContext* sphere();

  class  QuadContext : public antlr4::ParserRuleContext {
  public:
    QuadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUAD();
    std::vector<PositionContext *> position();
    PositionContext* position(size_t i);
    DiffuseContext *diffuse();
    SpecularContext *specular();
    AmbientContext *ambient();
    antlr4::tree::TerminalNode *MIRROR();
    antlr4::tree::TerminalNode *DIFFUSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuadContext* quad();

  class  RadiusContext : public antlr4::ParserRuleContext {
  public:
    RadiusContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RADIUS();
    antlr4::tree::TerminalNode *NUMBER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RadiusContext* radius();

  class  PositionContext : public antlr4::ParserRuleContext {
  public:
    PositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POS();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PositionContext* position();

  class  DiffuseContext : public antlr4::ParserRuleContext {
  public:
    DiffuseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIFF();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiffuseContext* diffuse();

  class  SpecularContext : public antlr4::ParserRuleContext {
  public:
    SpecularContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SPEC();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SpecularContext* specular();

  class  AmbientContext : public antlr4::ParserRuleContext {
  public:
    AmbientContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AMB();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AmbientContext* ambient();

  class  ResolutionContext : public antlr4::ParserRuleContext {
  public:
    ResolutionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESOLUTION();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResolutionContext* resolution();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

