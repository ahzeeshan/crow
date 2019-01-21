//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef CROWAPP_H
#define CROWAPP_H

#include "MooseApp.h"

class crowApp;

template <>
InputParameters validParams<crowApp>();

class crowApp : public MooseApp
{
public:
  crowApp(InputParameters parameters);
  virtual ~crowApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* CROWAPP_H */
