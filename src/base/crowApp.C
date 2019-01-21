#include "crowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<crowApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

crowApp::crowApp(InputParameters parameters) : MooseApp(parameters)
{
  crowApp::registerAll(_factory, _action_factory, _syntax);
}

crowApp::~crowApp() {}

void
crowApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"crowApp"});
  Registry::registerActionsTo(af, {"crowApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
crowApp::registerApps()
{
  registerApp(crowApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
crowApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  crowApp::registerAll(f, af, s);
}
extern "C" void
crowApp__registerApps()
{
  crowApp::registerApps();
}
