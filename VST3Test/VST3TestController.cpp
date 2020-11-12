#include "pluginterfaces/base/ibstream.h"
#include "base/source/fstreamer.h"

#include "VST3Test.h"
#include "VST3TestController.h"

VST3TestController::VST3TestController(void)
{
}

VST3TestController::~VST3TestController(void)
{
}

tresult PLUGIN_API VST3TestController::initialize(FUnknown* context)
{
	tresult result = EditController::initialize(context);

	if (result != kResultOk)
	{
		return result;
	}

	parameters.addParameter(STR16("Gain"), nullptr, 0, 0.5, ParameterInfo::kCanAutomate, kGainId);

	return result;
}

tresult PLUGIN_API VST3TestController::terminate()
{
	return EditController::terminate();
}

tresult PLUGIN_API VST3TestController::setComponentState(IBStream* state)
{
	if (!state)
		return kResultFalse;

	IBStreamer streamer(state, kLittleEndian);

	float savedGain = 0.f;
	if (streamer.readFloat(savedGain) == false)
		return kResultFalse;

	setParamNormalized(kGainId, savedGain);

	return kResultOk;
}
