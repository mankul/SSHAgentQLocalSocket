import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import client 1.0
import session 1.0


Window {

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property variant clientList : []
    property int clientNumber: 0


    ClientSessions{
        id: clientSessions
    }



    function createNewClient(){
        console.log("create new client")
        clientSessions.createNewClientSocket()
        clientSessions.connectClientToServer()
    }

    function getAddedIdentities(){
        console.log("qml button clicked: Get all added identities");
        clientSessions.fetchAddedIdentities()
    }

    Row{
        padding: 50
        Column{

            padding: 10
            Label{
                id: client
                text: "ClientSet"
            }
            TextField{
                id: clientText
                text: client.text
            }

            Button{
                id: clientInit
                text: "Create New Client"
                onClicked: createNewClient()
            }
            Button{
                id:getIdentities
                text:"Get SSH Ids"
                onClicked: getAddedIdentities()
            }

        }
        Column{
            padding: 10

            Label{
                id: server
                text: "SSH Server"
            }
            TextField{
                id: serverName
                text: "Server (WAIT)"
            }

            Button{
                id: serverClick
                text: "Click!"
            }
        }




    }
}
