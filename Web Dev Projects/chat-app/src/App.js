
import { ChatEngine } from "react-chat-engine";
import ChatFeed from "./components/ChatFeed";
import Login from "./components/Login";
import "./App.css";

require('dotenv').config();

const projectId ="d5b60537-b785-4e16-bf7d-4d366a5ad8a5";

const App = () =>{

    if(!localStorage.getItem("username")) return <Login/>;

    return (
        <ChatEngine
			height="100vh"
			userName={localStorage.getItem("username")}
			userSecret={localStorage.getItem("password")}
			projectID={projectId}
            renderChatFeed={(chatAppProps) => <ChatFeed {...chatAppProps} />}
		/>
    );
};

export default App;