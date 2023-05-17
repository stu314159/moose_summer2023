//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MooseSummer2023TestApp.h"
#include "MooseSummer2023App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
MooseSummer2023TestApp::validParams()
{
  InputParameters params = MooseSummer2023App::validParams();
  return params;
}

MooseSummer2023TestApp::MooseSummer2023TestApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseSummer2023TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MooseSummer2023TestApp::~MooseSummer2023TestApp() {}

void
MooseSummer2023TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MooseSummer2023App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MooseSummer2023TestApp"});
    Registry::registerActionsTo(af, {"MooseSummer2023TestApp"});
  }
}

void
MooseSummer2023TestApp::registerApps()
{
  registerApp(MooseSummer2023App);
  registerApp(MooseSummer2023TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MooseSummer2023TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseSummer2023TestApp::registerAll(f, af, s);
}
extern "C" void
MooseSummer2023TestApp__registerApps()
{
  MooseSummer2023TestApp::registerApps();
}
