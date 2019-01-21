//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "crowTestApp.h"
#include "crowApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<crowTestApp>()
{
  InputParameters params = validParams<crowApp>();
  return params;
}

crowTestApp::crowTestApp(InputParameters parameters) : MooseApp(parameters)
{
  crowTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

crowTestApp::~crowTestApp() {}

void
crowTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  crowApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"crowTestApp"});
    Registry::registerActionsTo(af, {"crowTestApp"});
  }
}

void
crowTestApp::registerApps()
{
  registerApp(crowApp);
  registerApp(crowTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
crowTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  crowTestApp::registerAll(f, af, s);
}
extern "C" void
crowTestApp__registerApps()
{
  crowTestApp::registerApps();
}
