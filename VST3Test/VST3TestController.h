#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

// Plugin controller GUID - must be unique
static const FUID VST3TestControllerUID(0x2409F0E2, 0xE2694E28, 0xB27CC812, 0xCE0AC04B);

class VST3TestController : public EditController
{
public:
	VST3TestController(void);

	static FUnknown* createInstance(void* context)
	{
		return (IEditController*) new VST3TestController;
	}

	tresult PLUGIN_API initialize(FUnknown* context);
	tresult PLUGIN_API terminate();

	tresult PLUGIN_API setComponentState(IBStream* state);

	// Uncomment to add a GUI
	// IPlugView * PLUGIN_API createView (const char * name);

	// Uncomment to override default EditController behavior
	// tresult PLUGIN_API setState(IBStream* state);
	// tresult PLUGIN_API getState(IBStream* state);
	// tresult PLUGIN_API setParamNormalized(ParamID tag, ParamValue value);
	// tresult PLUGIN_API getParamStringByValue(ParamID tag, ParamValue valueNormalized, String128 string);
	// tresult PLUGIN_API getParamValueByString(ParamID tag, TChar* string, ParamValue& valueNormalized);

	~VST3TestController(void);
};

