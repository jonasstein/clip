#include "core/fitobject.h"

FitParameterGroup::~FitParameterGroup()  {
  foreach (FitParameter* p, groupParameters)
    delete p;
  groupParameters.clear();
}

void FitParameterGroup::setValue() {
  if (valuesCached) {
    QList<double> values;
    foreach(FitParameter* p, groupParameters)
      values +=p->getCachedValue();
    doSetValue(values);
  }
  valuesCached=false;
}

void FitParameterGroup::addParameter(QString name)  {
  groupParameters += new FitParameter(name, groupParameters.size(), *this);
}



void FitObject::addParameterGroup(FitParameterGroup* g) {
  groups << g;
}

QList<FitParameter*> FitObject::allParameters() const {
  QList<FitParameter*>  list;
  foreach (FitParameterGroup* g, groups)
    list += g->parameters();
  return list;
}

QList<FitParameter*> FitObject::changeableParameters() const {
  QList<FitParameter*>  list;
  foreach (FitParameterGroup* g, groups)
    foreach (FitParameter* p, g->parameters())
      if (p->isChangeable())
        list += p;
  return list;
}

QList<FitParameter*> FitObject::enabledParameters() const {
  QList<FitParameter*>  list;
  foreach (FitParameterGroup* g, groups)
    foreach (FitParameter* p, g->parameters())
      if (p->isEnabled())
        list += p;
  return list;
}
