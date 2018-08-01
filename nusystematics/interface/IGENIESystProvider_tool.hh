#ifndef nusystematics_INTERFACE_IGENIESYSTPROVIDER_TOOL_SEEN
#define nusystematics_INTERFACE_IGENIESYSTPROVIDER_TOOL_SEEN

#include "systematicstools/interface/ISystProviderTool.hh"

#include "fhiclcpp/ParameterSet.h"

// GENIE
#include "EVGCore/EventRecord.h"

namespace nusyst {
class IGENIESystProvider_tool : public systtools::ISystProviderTool {
public:
  IGENIESystProvider_tool(fhicl::ParameterSet const &ps)
      : ISystProviderTool(ps) {}

  /// Calculates configured response for a given GHep record
  virtual systtools::event_unit_response_t
  GetEventResponse(genie::EventRecord &) = 0;
  /// Calculates the response to a single parameter for a given GHep record
  virtual systtools::event_unit_response_t
  GetEventResponse(genie::EventRecord &, systtools::paramId_t) {
    throw systtools::ISystProviderTool_method_unimplemented()
        << "[ERROR]: " << GetFullyQualifiedName()
        << " does not implement systtools::event_unit_response_t "
           "GetEventResponse(genie::EventRecord &, systtools::paramId_t).";
  }

  /// Calculates the multiplicatively combined responses for a given set of
  /// parameter--value pairs.
  ///
  /// \note This convenience method should only be used for weight responses.
  virtual double GetEventWeightResponse(genie::EventRecord &,
                                        systtools::param_value_list_t const &) {
    throw systtools::ISystProviderTool_method_unimplemented()
        << "[ERROR]: " << GetFullyQualifiedName()
        << " does not implement double "
           "GetEventWeightResponse(genie::EventRecord "
           "&,systtools::param_value_list_t const &).";
  }
};
} // namespace nusyst

#endif
