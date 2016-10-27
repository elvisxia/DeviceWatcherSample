//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace DeviceWatcherCppSample
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
		

	private:
		void btnClick_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void OnAdded(Windows::Devices::Enumeration::DeviceWatcher ^sender, Windows::Devices::Enumeration::DeviceInformation ^args);
		void OnRemoved(Windows::Devices::Enumeration::DeviceWatcher ^sender, Windows::Devices::Enumeration::DeviceInformationUpdate ^args);
		void OnUpdated(Windows::Devices::Enumeration::DeviceWatcher ^sender, Windows::Devices::Enumeration::DeviceInformationUpdate ^args);
		void DispatcherHandler();


		Windows::Foundation::EventRegistrationToken handlerAddedToken;
		Windows::Foundation::EventRegistrationToken handlerUpdatedToken;
		Windows::Foundation::EventRegistrationToken handlerRemovedToken;
		Windows::Devices::Enumeration::DeviceWatcher^ watcher;
	};
}
