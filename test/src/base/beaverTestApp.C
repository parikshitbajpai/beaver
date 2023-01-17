//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "beaverTestApp.h"
#include "beaverApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
beaverTestApp::validParams()
{
  InputParameters params = beaverApp::validParams();
  return params;
}

beaverTestApp::beaverTestApp(InputParameters parameters) : MooseApp(parameters)
{
  beaverTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

beaverTestApp::~beaverTestApp() {}

void
beaverTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  beaverApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"beaverTestApp"});
    Registry::registerActionsTo(af, {"beaverTestApp"});
  }
}

void
beaverTestApp::registerApps()
{
  registerApp(beaverApp);
  registerApp(beaverTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
beaverTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  beaverTestApp::registerAll(f, af, s);
}
extern "C" void
beaverTestApp__registerApps()
{
  beaverTestApp::registerApps();
}
