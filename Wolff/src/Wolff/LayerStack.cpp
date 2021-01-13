#include "Wolffpch.h"
#include "LayerStack.h"

namespace Wolff {

	LayerStack::LayerStack()
	{
		layerInsert = layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		layerInsert = layers.emplace(layerInsert, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		std::vector<Layer*>::iterator it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end())
		{
			layers.erase(it);
			layerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		std::vector<Layer*>::iterator it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end())
			layers.erase(it);
	}
}