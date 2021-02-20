
// Generated from scene.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "sceneParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by sceneParser.
 */
class  sceneVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by sceneParser.
   */
    virtual antlrcpp::Any visitScene(sceneParser::SceneContext *context) = 0;

    virtual antlrcpp::Any visitParamlist(sceneParser::ParamlistContext *context) = 0;

    virtual antlrcpp::Any visitParam(sceneParser::ParamContext *context) = 0;

    virtual antlrcpp::Any visitObject(sceneParser::ObjectContext *context) = 0;

    virtual antlrcpp::Any visitLight(sceneParser::LightContext *context) = 0;

    virtual antlrcpp::Any visitSphere(sceneParser::SphereContext *context) = 0;

    virtual antlrcpp::Any visitQuad(sceneParser::QuadContext *context) = 0;

    virtual antlrcpp::Any visitRadius(sceneParser::RadiusContext *context) = 0;

    virtual antlrcpp::Any visitPosition(sceneParser::PositionContext *context) = 0;

    virtual antlrcpp::Any visitDiffuse(sceneParser::DiffuseContext *context) = 0;

    virtual antlrcpp::Any visitSpecular(sceneParser::SpecularContext *context) = 0;

    virtual antlrcpp::Any visitAmbient(sceneParser::AmbientContext *context) = 0;

    virtual antlrcpp::Any visitResolution(sceneParser::ResolutionContext *context) = 0;


};

