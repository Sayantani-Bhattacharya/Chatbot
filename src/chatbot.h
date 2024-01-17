#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot(); //destructor

    //// STUDENT CODE   

    ChatBot(const ChatBot &source); //copy constructor
    ChatBot (ChatBot &&source); //move constructor
    ChatBot &operator=(const ChatBot &source); //copy assignment operator
    ChatBot &operator = (ChatBot &&source); //move assignment operator   

    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    //set current node code has embeded send msg to user, so when current node is set in a particular node then only the node's answer in sent to the user via chatlogic,
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
