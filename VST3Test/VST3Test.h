#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"
#include "public.sdk/source/vst/vstaudioeffect.h"
#include "base/source/fstring.h"
#include "pluginterfaces/base/funknown.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

// Parameter enumeration
enum
{
	kGainId = 0
};

// Plugin processor GUID - must be unique
static const FUID VST3TestProcessorUID(0xFED5C5BC, 0xE7E14A3D, 0xBB53CDF8, 0xCADB7D5D);

class VST3Test : public AudioEffect
{
public:
	VST3Test(void);

	static FUnknown* createInstance(void* context)
	{
		return (IAudioProcessor*) new VST3Test();
	}

	tresult PLUGIN_API initialize(FUnknown* context);
	tresult PLUGIN_API terminate();
	tresult PLUGIN_API setActive(TBool state);
	tresult PLUGIN_API setupProcessing(ProcessSetup& newSetup);
	tresult PLUGIN_API process(ProcessData& data);
	tresult PLUGIN_API setState(IBStream* state);
	tresult PLUGIN_API getState(IBStream* state);
	tresult PLUGIN_API setBusArrangements(SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts);
	~VST3Test(void);

private:
	float gain = 0.5;
};
