#include "RTVisitor.h"

antlrcpp::Any RTVisitor::visitScene(sceneParser::SceneContext* ctx)
{
	scene tmpScene = scene();

	//visitChildren(ctx);
	for (auto& object : ctx->object()) {
		if (object->light()) {
			Light* tmp = (visitObject(object)).as<Light*>();
			tmpScene.lights.push_back(tmp);
		}
		else if (object->quad()) {
			Shape* tmp = (visitObject(object)).as<Quad*>();
			tmpScene.shapes.push_back(tmp);
		}
		else if (object->sphere()) {
			Shape* tmp = (visitObject(object)).as<Sphere*>();
			tmpScene.shapes.push_back(tmp);
		}
		
	}

	for (auto& paramctx : ctx->paramlist()->param()) {
		if (paramctx->SHININESS()) {
			tmpScene.shininess = stof(paramctx->NUMBER()[0]->getText());
		}
		 else if (paramctx->ANTIALIAS()) {
			tmpScene.antialias = stoi(paramctx->NUMBER()[0]->getText());
		}
		else if (paramctx->MAXDEPTH()) {
			tmpScene.maxDepth = stoi(paramctx->NUMBER()[0]->getText());
		}
		else if (paramctx->BACKGROUND()) {
			vector<int> vals;
			for (auto& element : paramctx->NUMBER()) {
				vals.push_back(stoi(element->getText()));
			}
			glm::vec3 color = glm::vec3(vals[0], vals[1], vals[2]);
			tmpScene.backgroundColor = color;
		}
	}

	tmpScene.resolutionW = stoi(ctx->resolution()->NUMBER()[0]->getText());
	tmpScene.resolutionH = stoi(ctx->resolution()->NUMBER()[1]->getText());


	antlrcpp::Any result = tmpScene;
	return tmpScene;
}

antlrcpp::Any RTVisitor::visitObject(sceneParser::ObjectContext* ctx)
{
	Shape tmp;
	if (ctx->sphere()) {
		return visitSphere(ctx->sphere());
	}
	if (ctx->quad()) {
		return visitQuad(ctx->quad());
	}
	if (ctx->light()) {
		return visitLight(ctx->light());
	}

}

antlrcpp::Any RTVisitor::visitSphere(sceneParser::SphereContext* ctx)
{
	Sphere* tmp = new Sphere();
	tmp->position = visitPosition(ctx->position());
	tmp->radius = stoi(ctx->radius()->NUMBER()->getText());
	tmp->ambient = visitAmbient(ctx->ambient());
	tmp->specular = visitSpecular(ctx->specular());
	tmp->diffuse = visitDiffuse(ctx->diffuse());
	if (ctx->MIRROR()) tmp->isMirror = true;
	antlrcpp::Any result = tmp;
	return tmp;
}

antlrcpp::Any RTVisitor::visitQuad(sceneParser::QuadContext* ctx)
{
	Quad* tmp = new Quad();
	vector<glm::vec3> corners;
	for (auto& corner : ctx->position()) {
		corners.push_back(visitPosition(corner));
	}
	tmp->corner1 = corners[0];
	tmp->corner2 = corners[1];
	tmp->corner3 = corners[2];
	   
	tmp->ambient = visitAmbient(ctx->ambient());
	tmp->specular = visitSpecular(ctx->specular());
	tmp->diffuse = visitDiffuse(ctx->diffuse());
	if (ctx->MIRROR()) tmp->isMirror = true;

	antlrcpp::Any result = tmp;
	return tmp;
}

antlrcpp::Any RTVisitor::visitLight(sceneParser::LightContext* ctx)
{
	Light* tmp = new Light();
	tmp->position = visitPosition(ctx->position());
	tmp->specular = visitSpecular(ctx->specular());
	tmp->diffuse = visitDiffuse(ctx->diffuse());

	antlrcpp::Any result = tmp;
	return tmp;
}

antlrcpp::Any RTVisitor::visitPosition(sceneParser::PositionContext* ctx)
{
	vector<int> vals;
	for (auto& element : ctx->NUMBER()) {
		vals.push_back(stoi(element->getText()));
	}
	glm::vec3 pos = glm::vec3(vals[0], vals[1], vals[2]);
	antlrcpp::Any result = pos;
	return result;
}

antlrcpp::Any RTVisitor::visitAmbient(sceneParser::AmbientContext* ctx)
{
	vector<int> vals;
	for (auto& element : ctx->NUMBER()) {
		vals.push_back(stoi(element->getText()));
	}
	glm::vec3 ambient = glm::vec3(vals[0], vals[1], vals[2]);
	antlrcpp::Any result = ambient;
	return result;
}

antlrcpp::Any RTVisitor::visitSpecular(sceneParser::SpecularContext* ctx)
{
	vector<int> vals;
	for (auto& element : ctx->NUMBER()) {
		vals.push_back(stoi(element->getText()));
	}
	glm::vec3 specular = glm::vec3(vals[0], vals[1], vals[2]);
	antlrcpp::Any result = specular;
	return result;
}

antlrcpp::Any RTVisitor::visitDiffuse(sceneParser::DiffuseContext* ctx)
{
	vector<int> vals;
	for (auto& element : ctx->NUMBER()) {
		vals.push_back(stoi(element->getText()));
	}
	glm::vec3 diffuse = glm::vec3(vals[0], vals[1], vals[2]);
	antlrcpp::Any result = diffuse;
	return result;
}
