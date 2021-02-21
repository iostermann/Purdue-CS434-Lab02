
// Generated from scene.g4 by ANTLR 4.9.1


#include "sceneVisitor.h"

#include "sceneParser.h"


using namespace antlrcpp;
using namespace antlr4;

sceneParser::sceneParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

sceneParser::~sceneParser() {
  delete _interpreter;
}

std::string sceneParser::getGrammarFileName() const {
  return "scene.g4";
}

const std::vector<std::string>& sceneParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& sceneParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SceneContext ------------------------------------------------------------------

sceneParser::SceneContext::SceneContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sceneParser::ParamlistContext* sceneParser::SceneContext::paramlist() {
  return getRuleContext<sceneParser::ParamlistContext>(0);
}

sceneParser::ResolutionContext* sceneParser::SceneContext::resolution() {
  return getRuleContext<sceneParser::ResolutionContext>(0);
}

tree::TerminalNode* sceneParser::SceneContext::EOF() {
  return getToken(sceneParser::EOF, 0);
}

std::vector<sceneParser::ObjectContext *> sceneParser::SceneContext::object() {
  return getRuleContexts<sceneParser::ObjectContext>();
}

sceneParser::ObjectContext* sceneParser::SceneContext::object(size_t i) {
  return getRuleContext<sceneParser::ObjectContext>(i);
}


size_t sceneParser::SceneContext::getRuleIndex() const {
  return sceneParser::RuleScene;
}


antlrcpp::Any sceneParser::SceneContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitScene(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::SceneContext* sceneParser::scene() {
  SceneContext *_localctx = _tracker.createInstance<SceneContext>(_ctx, getState());
  enterRule(_localctx, 0, sceneParser::RuleScene);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    paramlist();
    setState(28); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(27);
      object();
      setState(30); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << sceneParser::LIGHT)
      | (1ULL << sceneParser::SPHERE)
      | (1ULL << sceneParser::QUAD))) != 0));
    setState(32);
    resolution();
    setState(33);
    match(sceneParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamlistContext ------------------------------------------------------------------

sceneParser::ParamlistContext::ParamlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sceneParser::ParamContext *> sceneParser::ParamlistContext::param() {
  return getRuleContexts<sceneParser::ParamContext>();
}

sceneParser::ParamContext* sceneParser::ParamlistContext::param(size_t i) {
  return getRuleContext<sceneParser::ParamContext>(i);
}


size_t sceneParser::ParamlistContext::getRuleIndex() const {
  return sceneParser::RuleParamlist;
}


antlrcpp::Any sceneParser::ParamlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitParamlist(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::ParamlistContext* sceneParser::paramlist() {
  ParamlistContext *_localctx = _tracker.createInstance<ParamlistContext>(_ctx, getState());
  enterRule(_localctx, 2, sceneParser::RuleParamlist);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(35);
      param();
      setState(38); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << sceneParser::SHININESS)
      | (1ULL << sceneParser::ANTIALIAS)
      | (1ULL << sceneParser::BACKGROUND)
      | (1ULL << sceneParser::MAXDEPTH))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

sceneParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::ParamContext::SHININESS() {
  return getToken(sceneParser::SHININESS, 0);
}

std::vector<tree::TerminalNode *> sceneParser::ParamContext::NUMBER() {
  return getTokens(sceneParser::NUMBER);
}

tree::TerminalNode* sceneParser::ParamContext::NUMBER(size_t i) {
  return getToken(sceneParser::NUMBER, i);
}

tree::TerminalNode* sceneParser::ParamContext::ANTIALIAS() {
  return getToken(sceneParser::ANTIALIAS, 0);
}

tree::TerminalNode* sceneParser::ParamContext::BACKGROUND() {
  return getToken(sceneParser::BACKGROUND, 0);
}

tree::TerminalNode* sceneParser::ParamContext::MAXDEPTH() {
  return getToken(sceneParser::MAXDEPTH, 0);
}


size_t sceneParser::ParamContext::getRuleIndex() const {
  return sceneParser::RuleParam;
}


antlrcpp::Any sceneParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::ParamContext* sceneParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 4, sceneParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(50);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sceneParser::SHININESS: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        match(sceneParser::SHININESS);
        setState(41);
        match(sceneParser::NUMBER);
        break;
      }

      case sceneParser::ANTIALIAS: {
        enterOuterAlt(_localctx, 2);
        setState(42);
        match(sceneParser::ANTIALIAS);
        setState(43);
        match(sceneParser::NUMBER);
        break;
      }

      case sceneParser::BACKGROUND: {
        enterOuterAlt(_localctx, 3);
        setState(44);
        match(sceneParser::BACKGROUND);
        setState(45);
        match(sceneParser::NUMBER);
        setState(46);
        match(sceneParser::NUMBER);
        setState(47);
        match(sceneParser::NUMBER);
        break;
      }

      case sceneParser::MAXDEPTH: {
        enterOuterAlt(_localctx, 4);
        setState(48);
        match(sceneParser::MAXDEPTH);
        setState(49);
        match(sceneParser::NUMBER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

sceneParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sceneParser::LightContext* sceneParser::ObjectContext::light() {
  return getRuleContext<sceneParser::LightContext>(0);
}

sceneParser::SphereContext* sceneParser::ObjectContext::sphere() {
  return getRuleContext<sceneParser::SphereContext>(0);
}

sceneParser::QuadContext* sceneParser::ObjectContext::quad() {
  return getRuleContext<sceneParser::QuadContext>(0);
}


size_t sceneParser::ObjectContext::getRuleIndex() const {
  return sceneParser::RuleObject;
}


antlrcpp::Any sceneParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::ObjectContext* sceneParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 6, sceneParser::RuleObject);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sceneParser::LIGHT: {
        enterOuterAlt(_localctx, 1);
        setState(52);
        light();
        break;
      }

      case sceneParser::SPHERE: {
        enterOuterAlt(_localctx, 2);
        setState(53);
        sphere();
        break;
      }

      case sceneParser::QUAD: {
        enterOuterAlt(_localctx, 3);
        setState(54);
        quad();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LightContext ------------------------------------------------------------------

sceneParser::LightContext::LightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::LightContext::LIGHT() {
  return getToken(sceneParser::LIGHT, 0);
}

sceneParser::PositionContext* sceneParser::LightContext::position() {
  return getRuleContext<sceneParser::PositionContext>(0);
}

sceneParser::DiffuseContext* sceneParser::LightContext::diffuse() {
  return getRuleContext<sceneParser::DiffuseContext>(0);
}

sceneParser::SpecularContext* sceneParser::LightContext::specular() {
  return getRuleContext<sceneParser::SpecularContext>(0);
}


size_t sceneParser::LightContext::getRuleIndex() const {
  return sceneParser::RuleLight;
}


antlrcpp::Any sceneParser::LightContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitLight(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::LightContext* sceneParser::light() {
  LightContext *_localctx = _tracker.createInstance<LightContext>(_ctx, getState());
  enterRule(_localctx, 8, sceneParser::RuleLight);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(sceneParser::LIGHT);
    setState(58);
    position();
    setState(59);
    diffuse();
    setState(60);
    specular();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SphereContext ------------------------------------------------------------------

sceneParser::SphereContext::SphereContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::SphereContext::SPHERE() {
  return getToken(sceneParser::SPHERE, 0);
}

sceneParser::PositionContext* sceneParser::SphereContext::position() {
  return getRuleContext<sceneParser::PositionContext>(0);
}

sceneParser::RadiusContext* sceneParser::SphereContext::radius() {
  return getRuleContext<sceneParser::RadiusContext>(0);
}

sceneParser::DiffuseContext* sceneParser::SphereContext::diffuse() {
  return getRuleContext<sceneParser::DiffuseContext>(0);
}

sceneParser::SpecularContext* sceneParser::SphereContext::specular() {
  return getRuleContext<sceneParser::SpecularContext>(0);
}

sceneParser::AmbientContext* sceneParser::SphereContext::ambient() {
  return getRuleContext<sceneParser::AmbientContext>(0);
}

tree::TerminalNode* sceneParser::SphereContext::MIRROR() {
  return getToken(sceneParser::MIRROR, 0);
}

tree::TerminalNode* sceneParser::SphereContext::DIFFUSE() {
  return getToken(sceneParser::DIFFUSE, 0);
}


size_t sceneParser::SphereContext::getRuleIndex() const {
  return sceneParser::RuleSphere;
}


antlrcpp::Any sceneParser::SphereContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitSphere(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::SphereContext* sceneParser::sphere() {
  SphereContext *_localctx = _tracker.createInstance<SphereContext>(_ctx, getState());
  enterRule(_localctx, 10, sceneParser::RuleSphere);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    match(sceneParser::SPHERE);
    setState(63);
    position();
    setState(64);
    radius();
    setState(65);
    diffuse();
    setState(66);
    specular();
    setState(67);
    ambient();
    setState(68);
    _la = _input->LA(1);
    if (!(_la == sceneParser::MIRROR

    || _la == sceneParser::DIFFUSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuadContext ------------------------------------------------------------------

sceneParser::QuadContext::QuadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::QuadContext::QUAD() {
  return getToken(sceneParser::QUAD, 0);
}

std::vector<sceneParser::PositionContext *> sceneParser::QuadContext::position() {
  return getRuleContexts<sceneParser::PositionContext>();
}

sceneParser::PositionContext* sceneParser::QuadContext::position(size_t i) {
  return getRuleContext<sceneParser::PositionContext>(i);
}

sceneParser::DiffuseContext* sceneParser::QuadContext::diffuse() {
  return getRuleContext<sceneParser::DiffuseContext>(0);
}

sceneParser::SpecularContext* sceneParser::QuadContext::specular() {
  return getRuleContext<sceneParser::SpecularContext>(0);
}

sceneParser::AmbientContext* sceneParser::QuadContext::ambient() {
  return getRuleContext<sceneParser::AmbientContext>(0);
}

tree::TerminalNode* sceneParser::QuadContext::MIRROR() {
  return getToken(sceneParser::MIRROR, 0);
}

tree::TerminalNode* sceneParser::QuadContext::DIFFUSE() {
  return getToken(sceneParser::DIFFUSE, 0);
}


size_t sceneParser::QuadContext::getRuleIndex() const {
  return sceneParser::RuleQuad;
}


antlrcpp::Any sceneParser::QuadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitQuad(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::QuadContext* sceneParser::quad() {
  QuadContext *_localctx = _tracker.createInstance<QuadContext>(_ctx, getState());
  enterRule(_localctx, 12, sceneParser::RuleQuad);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(sceneParser::QUAD);
    setState(71);
    position();
    setState(72);
    position();
    setState(73);
    position();
    setState(74);
    diffuse();
    setState(75);
    specular();
    setState(76);
    ambient();
    setState(77);
    _la = _input->LA(1);
    if (!(_la == sceneParser::MIRROR

    || _la == sceneParser::DIFFUSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RadiusContext ------------------------------------------------------------------

sceneParser::RadiusContext::RadiusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::RadiusContext::RADIUS() {
  return getToken(sceneParser::RADIUS, 0);
}

tree::TerminalNode* sceneParser::RadiusContext::NUMBER() {
  return getToken(sceneParser::NUMBER, 0);
}


size_t sceneParser::RadiusContext::getRuleIndex() const {
  return sceneParser::RuleRadius;
}


antlrcpp::Any sceneParser::RadiusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitRadius(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::RadiusContext* sceneParser::radius() {
  RadiusContext *_localctx = _tracker.createInstance<RadiusContext>(_ctx, getState());
  enterRule(_localctx, 14, sceneParser::RuleRadius);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(sceneParser::RADIUS);
    setState(80);
    match(sceneParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PositionContext ------------------------------------------------------------------

sceneParser::PositionContext::PositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::PositionContext::POS() {
  return getToken(sceneParser::POS, 0);
}

std::vector<tree::TerminalNode *> sceneParser::PositionContext::NUMBER() {
  return getTokens(sceneParser::NUMBER);
}

tree::TerminalNode* sceneParser::PositionContext::NUMBER(size_t i) {
  return getToken(sceneParser::NUMBER, i);
}


size_t sceneParser::PositionContext::getRuleIndex() const {
  return sceneParser::RulePosition;
}


antlrcpp::Any sceneParser::PositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitPosition(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::PositionContext* sceneParser::position() {
  PositionContext *_localctx = _tracker.createInstance<PositionContext>(_ctx, getState());
  enterRule(_localctx, 16, sceneParser::RulePosition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(sceneParser::POS);
    setState(83);
    match(sceneParser::NUMBER);
    setState(84);
    match(sceneParser::NUMBER);
    setState(85);
    match(sceneParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiffuseContext ------------------------------------------------------------------

sceneParser::DiffuseContext::DiffuseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::DiffuseContext::DIFF() {
  return getToken(sceneParser::DIFF, 0);
}

std::vector<tree::TerminalNode *> sceneParser::DiffuseContext::NUMBER() {
  return getTokens(sceneParser::NUMBER);
}

tree::TerminalNode* sceneParser::DiffuseContext::NUMBER(size_t i) {
  return getToken(sceneParser::NUMBER, i);
}


size_t sceneParser::DiffuseContext::getRuleIndex() const {
  return sceneParser::RuleDiffuse;
}


antlrcpp::Any sceneParser::DiffuseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitDiffuse(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::DiffuseContext* sceneParser::diffuse() {
  DiffuseContext *_localctx = _tracker.createInstance<DiffuseContext>(_ctx, getState());
  enterRule(_localctx, 18, sceneParser::RuleDiffuse);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(sceneParser::DIFF);
    setState(88);
    match(sceneParser::NUMBER);
    setState(89);
    match(sceneParser::NUMBER);
    setState(90);
    match(sceneParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpecularContext ------------------------------------------------------------------

sceneParser::SpecularContext::SpecularContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::SpecularContext::SPEC() {
  return getToken(sceneParser::SPEC, 0);
}

std::vector<tree::TerminalNode *> sceneParser::SpecularContext::NUMBER() {
  return getTokens(sceneParser::NUMBER);
}

tree::TerminalNode* sceneParser::SpecularContext::NUMBER(size_t i) {
  return getToken(sceneParser::NUMBER, i);
}


size_t sceneParser::SpecularContext::getRuleIndex() const {
  return sceneParser::RuleSpecular;
}


antlrcpp::Any sceneParser::SpecularContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitSpecular(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::SpecularContext* sceneParser::specular() {
  SpecularContext *_localctx = _tracker.createInstance<SpecularContext>(_ctx, getState());
  enterRule(_localctx, 20, sceneParser::RuleSpecular);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(sceneParser::SPEC);
    setState(93);
    match(sceneParser::NUMBER);
    setState(94);
    match(sceneParser::NUMBER);
    setState(95);
    match(sceneParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AmbientContext ------------------------------------------------------------------

sceneParser::AmbientContext::AmbientContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::AmbientContext::AMB() {
  return getToken(sceneParser::AMB, 0);
}

std::vector<tree::TerminalNode *> sceneParser::AmbientContext::NUMBER() {
  return getTokens(sceneParser::NUMBER);
}

tree::TerminalNode* sceneParser::AmbientContext::NUMBER(size_t i) {
  return getToken(sceneParser::NUMBER, i);
}


size_t sceneParser::AmbientContext::getRuleIndex() const {
  return sceneParser::RuleAmbient;
}


antlrcpp::Any sceneParser::AmbientContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitAmbient(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::AmbientContext* sceneParser::ambient() {
  AmbientContext *_localctx = _tracker.createInstance<AmbientContext>(_ctx, getState());
  enterRule(_localctx, 22, sceneParser::RuleAmbient);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(sceneParser::AMB);
    setState(98);
    match(sceneParser::NUMBER);
    setState(99);
    match(sceneParser::NUMBER);
    setState(100);
    match(sceneParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResolutionContext ------------------------------------------------------------------

sceneParser::ResolutionContext::ResolutionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sceneParser::ResolutionContext::RESOLUTION() {
  return getToken(sceneParser::RESOLUTION, 0);
}

std::vector<tree::TerminalNode *> sceneParser::ResolutionContext::NUMBER() {
  return getTokens(sceneParser::NUMBER);
}

tree::TerminalNode* sceneParser::ResolutionContext::NUMBER(size_t i) {
  return getToken(sceneParser::NUMBER, i);
}


size_t sceneParser::ResolutionContext::getRuleIndex() const {
  return sceneParser::RuleResolution;
}


antlrcpp::Any sceneParser::ResolutionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sceneVisitor*>(visitor))
    return parserVisitor->visitResolution(this);
  else
    return visitor->visitChildren(this);
}

sceneParser::ResolutionContext* sceneParser::resolution() {
  ResolutionContext *_localctx = _tracker.createInstance<ResolutionContext>(_ctx, getState());
  enterRule(_localctx, 24, sceneParser::RuleResolution);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    match(sceneParser::RESOLUTION);
    setState(103);
    match(sceneParser::NUMBER);
    setState(104);
    match(sceneParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> sceneParser::_decisionToDFA;
atn::PredictionContextCache sceneParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN sceneParser::_atn;
std::vector<uint16_t> sceneParser::_serializedATN;

std::vector<std::string> sceneParser::_ruleNames = {
  "scene", "paramlist", "param", "object", "light", "sphere", "quad", "radius", 
  "position", "diffuse", "specular", "ambient", "resolution"
};

std::vector<std::string> sceneParser::_literalNames = {
  "", "", "'SHININESS'", "'ANTIALIAS'", "'BACKGROUND'", "'MAXDEPTH'", "'RESOLUTION'", 
  "'LIGHT'", "'SPHERE'", "'QUAD'", "'POS'", "'DIFF'", "'SPEC'", "'AMB'", 
  "'RADIUS'", "'MIRROR'", "'DIFFUSE'", "", "", "", "' '"
};

std::vector<std::string> sceneParser::_symbolicNames = {
  "", "NUMBER", "SHININESS", "ANTIALIAS", "BACKGROUND", "MAXDEPTH", "RESOLUTION", 
  "LIGHT", "SPHERE", "QUAD", "POS", "DIFF", "SPEC", "AMB", "RADIUS", "MIRROR", 
  "DIFFUSE", "NEWLINE", "TAB", "COMMENT", "WHITESPACE"
};

dfa::Vocabulary sceneParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> sceneParser::_tokenNames;

sceneParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x16, 0x6d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x3, 0x2, 0x6, 0x2, 0x1f, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x20, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x6, 0x3, 0x27, 0xa, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0x28, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x35, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3a, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x2, 
    0x2, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x2, 0x3, 0x3, 0x2, 0x11, 0x12, 0x2, 0x66, 0x2, 0x1c, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x26, 0x3, 0x2, 0x2, 0x2, 0x6, 0x34, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x39, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0xe, 0x48, 0x3, 0x2, 0x2, 0x2, 0x10, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x54, 0x3, 0x2, 0x2, 0x2, 0x14, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x18, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 
    0x2, 0x1d, 0x1f, 0x5, 0x8, 0x5, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 
    0x5, 0x1a, 0xe, 0x2, 0x23, 0x24, 0x7, 0x2, 0x2, 0x3, 0x24, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x25, 0x27, 0x5, 0x6, 0x4, 0x2, 0x26, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x2b, 0x7, 0x4, 0x2, 0x2, 0x2b, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2c, 
    0x2d, 0x7, 0x5, 0x2, 0x2, 0x2d, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x2f, 
    0x7, 0x6, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x3, 0x2, 0x2, 0x30, 0x31, 0x7, 
    0x3, 0x2, 0x2, 0x31, 0x35, 0x7, 0x3, 0x2, 0x2, 0x32, 0x33, 0x7, 0x7, 
    0x2, 0x2, 0x33, 0x35, 0x7, 0x3, 0x2, 0x2, 0x34, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x3a, 0x5, 0xa, 0x6, 0x2, 0x37, 0x3a, 0x5, 0xc, 0x7, 0x2, 0x38, 0x3a, 
    0x5, 0xe, 0x8, 0x2, 0x39, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x9, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x3c, 0x7, 0x9, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x12, 0xa, 
    0x2, 0x3d, 0x3e, 0x5, 0x14, 0xb, 0x2, 0x3e, 0x3f, 0x5, 0x16, 0xc, 0x2, 
    0x3f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0xa, 0x2, 0x2, 0x41, 
    0x42, 0x5, 0x12, 0xa, 0x2, 0x42, 0x43, 0x5, 0x10, 0x9, 0x2, 0x43, 0x44, 
    0x5, 0x14, 0xb, 0x2, 0x44, 0x45, 0x5, 0x16, 0xc, 0x2, 0x45, 0x46, 0x5, 
    0x18, 0xd, 0x2, 0x46, 0x47, 0x9, 0x2, 0x2, 0x2, 0x47, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x49, 0x7, 0xb, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x12, 0xa, 
    0x2, 0x4a, 0x4b, 0x5, 0x12, 0xa, 0x2, 0x4b, 0x4c, 0x5, 0x12, 0xa, 0x2, 
    0x4c, 0x4d, 0x5, 0x14, 0xb, 0x2, 0x4d, 0x4e, 0x5, 0x16, 0xc, 0x2, 0x4e, 
    0x4f, 0x5, 0x18, 0xd, 0x2, 0x4f, 0x50, 0x9, 0x2, 0x2, 0x2, 0x50, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x10, 0x2, 0x2, 0x52, 0x53, 0x7, 
    0x3, 0x2, 0x2, 0x53, 0x11, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0xc, 
    0x2, 0x2, 0x55, 0x56, 0x7, 0x3, 0x2, 0x2, 0x56, 0x57, 0x7, 0x3, 0x2, 
    0x2, 0x57, 0x58, 0x7, 0x3, 0x2, 0x2, 0x58, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x5a, 0x7, 0xd, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x3, 0x2, 0x2, 0x5b, 
    0x5c, 0x7, 0x3, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x3, 0x2, 0x2, 0x5d, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0xe, 0x2, 0x2, 0x5f, 0x60, 0x7, 
    0x3, 0x2, 0x2, 0x60, 0x61, 0x7, 0x3, 0x2, 0x2, 0x61, 0x62, 0x7, 0x3, 
    0x2, 0x2, 0x62, 0x17, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0xf, 0x2, 
    0x2, 0x64, 0x65, 0x7, 0x3, 0x2, 0x2, 0x65, 0x66, 0x7, 0x3, 0x2, 0x2, 
    0x66, 0x67, 0x7, 0x3, 0x2, 0x2, 0x67, 0x19, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x69, 0x7, 0x8, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x3, 0x2, 0x2, 0x6a, 0x6b, 
    0x7, 0x3, 0x2, 0x2, 0x6b, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x20, 0x28, 
    0x34, 0x39, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

sceneParser::Initializer sceneParser::_init;
