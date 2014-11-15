#ifndef UTURN_H
#define UTURN_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Jordan
 */
class UTurn: public CommandBase {
public:
	UTurn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
