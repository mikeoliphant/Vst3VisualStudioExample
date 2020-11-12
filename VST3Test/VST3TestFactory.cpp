#include "VST3Test.h"
#include "VST3TestController.h"

#include "public.sdk/source/main/pluginfactory.h"

#define PluginCategory "Fx"
#define PluginName "VST3Test"

#define PLUGINVERSION "1.0.0"

bool InitModule()
{
	return true;
}

bool DeinitModule()
{
	return true;
}

// This creates the GetPluginFactory entry point that is exposed the the VST host
BEGIN_FACTORY_DEF("COMPANY",
	"WEBSITE",
	"CONTACT")

	//---First plug-in included in this factory-------
	// its kVstAudioEffectClass component
	DEF_CLASS2(INLINE_UID_FROM_FUID(VST3TestProcessorUID),
		PClassInfo::kManyInstances,	// cardinality
		kVstAudioEffectClass,	// the component category (do not changed this)
		PluginName,		// here the plug-in name (to be changed)
		Vst::kDistributable,	// means that component and controller could be distributed on different computers
		PluginCategory,		// Subcategory for this plug-in (to be changed)
		PLUGINVERSION,		// Plug-in version (to be changed)
		kVstVersionString,		// the VST 3 SDK version (do not changed this, use always this define)
		VST3Test::createInstance)	// function pointer called when this component should be instantiated

	// its kVstComponentControllerClass component
	DEF_CLASS2(INLINE_UID_FROM_FUID(VST3TestControllerUID),
		PClassInfo::kManyInstances, // cardinality
		kVstComponentControllerClass,// the Controller category (do not changed this)
		PluginName "Controller",	// controller name (could be the same than component name)
		0,						// not used here
		"",						// not used here
		PLUGINVERSION,		// Plug-in version (to be changed)
		kVstVersionString,		// the VST 3 SDK version (do not changed this, use always this define)
		VST3TestController::createInstance)// function pointer called when this component should be instantiated


END_FACTORY