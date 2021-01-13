#pragma once

#include "Wolff/Core.h"
#include "Wolff/Events/Event.h"

namespace Wolff {

	class WOLFF_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return debugName; }
	protected:
		std::string debugName;
	};
}