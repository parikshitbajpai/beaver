#include "beaverApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
beaverApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

beaverApp::beaverApp(InputParameters parameters) : MooseApp(parameters)
{
  beaverApp::registerAll(_factory, _action_factory, _syntax);
}

beaverApp::~beaverApp() {}

void
beaverApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"beaverApp"});
  Registry::registerActionsTo(af, {"beaverApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
beaverApp::registerApps()
{
  registerApp(beaverApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
beaverApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  beaverApp::registerAll(f, af, s);
}
extern "C" void
beaverApp__registerApps()
{
  beaverApp::registerApps();
}
