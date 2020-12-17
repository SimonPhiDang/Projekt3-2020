using System;
using System.ComponentModel;
using System.Linq;
using System.Net.Http;
using System.Net.WebSockets;
using System.Text;
using System.Threading;
using System.Windows;
using Websocket.Client;

namespace Beertress_Ansat
{

    public partial class MainWindow : Window
    {
        readonly Uri url = new Uri("ws://10.9.8.2:3000/");
        ClientWebSocket clientSocket = new ClientWebSocket();
        public string[] antal { get; set; }
        BindingList<string> listNames = new BindingList<string>();


        private async void BeertreesClicked(object sender, RoutedEventArgs e)
        {
            listNames.Add("BeerTrees opretter forbindelse");
            listNames.Add($"{clientSocket.State}");
            if (clientSocket.State == WebSocketState.Open)
            {
                var rcvBytes = new byte[128];
                var rcvBuffer = new ArraySegment<byte>(rcvBytes);
                WebSocketReceiveResult rcvResult = await clientSocket.ReceiveAsync(rcvBuffer, CancellationToken.None);
                byte[] msgBytes = rcvBuffer.Skip(rcvBuffer.Offset).Take(rcvResult.Count).ToArray();
                string rcvmes = Encoding.UTF8.GetString(msgBytes);

                listNames.Add(rcvmes);
            }
        }

        private void LstStatus_Initialized(object sender, System.EventArgs e)
        {
            LstStatus.ItemsSource = listNames; 
        }

        private void OderClicked(object sender, RoutedEventArgs e)
        {
			try
			{
                listNames.Add("Du har valgt at angive din bestilling");

                byte[] sendbytes = Encoding.UTF8.GetBytes("En besked fra beertress - Jubiii! :)");
                var sendbuffer = new ArraySegment<byte>(sendbytes);
                clientSocket.SendAsync(sendbuffer, WebSocketMessageType.Text, endOfMessage: true, CancellationToken.None);
            }
			catch (Exception)
			{
                listNames.Add("Noget gik galt: der er vidst ikke forbindelse til en server!");
				
			}
           
        }

        private void ExitCliked(object sender, RoutedEventArgs e)
        {
            listNames.Add("Du har valgt at afslutte din bestillingen");
            listNames.Add("Hyg dig - Svagdrikker! :-)");
        }

        private void LoadEventHandler(object sender, RoutedEventArgs e)
        {
			try
			{
                clientSocket.ConnectAsync(url, CancellationToken.None);
                listNames.Add($"{clientSocket.State}");
            }
			catch (Exception)
			{
                listNames.Add("Something went wrong: not connected!");
			}
            
        }
    }
}
//var response = httpClient.GetAsync("ws://localhost:3000/callBeerTrees");
//HttpClient httpClient = new HttpClient();
//ClientWebSocket webSocket = new ClientWebSocket();
