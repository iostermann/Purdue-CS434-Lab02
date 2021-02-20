
// Generated from scene.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "sceneVisitor.h"


/**
 * This class provides an empty implementation of sceneVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  sceneBaseVisitor : public sceneVisitor {
public:

  virtual antlrcpp::Any visitScene(sceneParser::SceneContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamlist(sceneParser::ParamlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam(sceneParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitObject(sceneParser::ObjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLight(sceneParser::LightContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSphere(sceneParser::SphereContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuad(sceneParser::QuadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRadius(sceneParser::RadiusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPosition(sceneParser::PositionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDiffuse(sceneParser::DiffuseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecular(sceneParser::SpecularContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAmbient(sceneParser::AmbientContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResolution(sceneParser::ResolutionContext *ctx) override {
    return visitChildren(ctx);
  }


};

