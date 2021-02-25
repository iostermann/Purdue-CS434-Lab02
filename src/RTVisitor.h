#pragma once
#include <string>
#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/sceneBaseVisitor.h"
#include "scene.h"
#include <any>

class RTVisitor : sceneBaseVisitor {
public:

	antlrcpp::Any visitScene(sceneParser::SceneContext* ctx);

	antlrcpp::Any visitObject(sceneParser::ObjectContext* ctx);
	antlrcpp::Any visitSphere(sceneParser::SphereContext* ctx);
	antlrcpp::Any visitQuad(sceneParser::QuadContext* ctx);
	antlrcpp::Any visitLight(sceneParser::LightContext* ctx);
	antlrcpp::Any visitPosition(sceneParser::PositionContext* ctx);

	antlrcpp::Any visitAmbient(sceneParser::AmbientContext* ctx);
	antlrcpp::Any visitSpecular(sceneParser::SpecularContext* ctx);
	antlrcpp::Any visitDiffuse(sceneParser::DiffuseContext* ctx);

};

