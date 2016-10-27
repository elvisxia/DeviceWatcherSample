//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace DeviceWatcherCppSample;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Devices::Enumeration;
using namespace Windows::UI::Core;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void DeviceWatcherCppSample::MainPage::btnClick_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	watcher=DeviceInformation::CreateWatcher(DeviceClass::AudioRender);
	handlerAddedToken=watcher->Added += ref new Windows::Foundation::TypedEventHandler<DeviceWatcher ^, DeviceInformation ^>(this, &DeviceWatcherCppSample::MainPage::OnAdded);

	handlerRemovedToken= watcher->Removed += ref new Windows::Foundation::TypedEventHandler<DeviceWatcher ^, DeviceInformationUpdate ^>(this, &DeviceWatcherCppSample::MainPage::OnRemoved);
	handlerUpdatedToken= watcher->Updated += ref new Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher ^, Windows::Devices::Enumeration::DeviceInformationUpdate ^>(this, &DeviceWatcherCppSample::MainPage::OnUpdated);
	watcher->Start();
}


void DeviceWatcherCppSample::MainPage::OnAdded(DeviceWatcher ^sender, DeviceInformation ^args)
{
	this->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([this, args]()
	{
		tbResult->Text = args->Name +"is Added";
	}));
}


void DeviceWatcherCppSample::MainPage::OnRemoved(DeviceWatcher ^sender, DeviceInformationUpdate ^args)
{
	this->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([this, args]()
	{
		tbResult->Text = args->Id + "is Removed";
	}));
}


void DeviceWatcherCppSample::MainPage::OnUpdated(Windows::Devices::Enumeration::DeviceWatcher ^sender, Windows::Devices::Enumeration::DeviceInformationUpdate ^args)
{
	this->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([this, args]()
	{
		tbResult->Text = args->Id + "is Updated";
	}));
	
}
