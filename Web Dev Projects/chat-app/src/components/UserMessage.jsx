import React from "react";

function UserMessage({ lastMessage, message }){

    const firstMessageByUser = !lastMessage || lastMessage.sender.username !== message.sender.username;

    return (
        <div className="message-row">

        {/* For first message by user */}
        {firstMessageByUser && (
            <div
                className="message-avatar"
                style={{ backgroundImage: message.sender && `url(${message.sender.avatar})` }}
            />
        )}

        
        {/* For normal messages */}
        {message?.attachments?.length>0
            ?(
                <img 
                    src={message.attachments[0].file}
                    alt="message-attachment"
                    className="message-image"
                    style ={ {marginLeft: firstMessageByUser ? "4px" : "48px"}}
                />
            ) :
            (
                <div className="message" style={ {float: "left", backgroundColor: "#CABCDC", marginLeft: firstMessageByUser ? "4px" : "48px"}}>
                    {message.text}
                </div>
            )
        }

        </div>
    );
}

export default UserMessage;