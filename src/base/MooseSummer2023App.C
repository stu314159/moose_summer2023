#include "MooseSummer2023App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MooseSummer2023App::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

MooseSummer2023App::MooseSummer2023App(InputParameters parameters) : MooseApp(parameters)
{
  MooseSummer2023App::registerAll(_factory, _action_factory, _syntax);
}

MooseSummer2023App::~MooseSummer2023App() {}

void
MooseSummer2023App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"MooseSummer2023App"});
  Registry::registerActionsTo(af, {"MooseSummer2023App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MooseSummer2023App::registerApps()
{
  registerApp(MooseSummer2023App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MooseSummer2023App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseSummer2023App::registerAll(f, af, s);
}
extern "C" void
MooseSummer2023App__registerApps()
{
  MooseSummer2023App::registerApps();
}
