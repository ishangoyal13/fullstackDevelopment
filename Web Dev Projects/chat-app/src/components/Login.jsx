import React, { useState } from "react";
import axios from "axios";

function Login(){

    const [username,setUsername] = useState("");
    const [password,setPassword] = useState("");
    const [error, setError] = useState("");

    const projectId = "d5b60537-b785-4e16-bf7d-4d366a5ad8a5";

    async function handleSubmit(event){
        event.preventDefault();

        const authObject = { "Project-ID": projectId, "User-Name": username, "User-Secret": password };

        try {
            await axios.get('https://api.chatengine.io/chats', { headers: authObject });
            
            localStorage.setItem("username", username);
            localStorage.setItem("password", password);
      
            window.location.reload();
            setError("");
        } catch (err) {
            setError("Oops... Incorrect Credentials....!");
        }

    }

    return (
        <div className="wrapper">
          <div className="form">
            <h1 className="title">Chat App🤩🤩</h1>
            
            <form onSubmit={handleSubmit}>
              <input type="text" value={username} 
                     onChange={(e) => setUsername(e.target.value)} 
                     className="input" 
                     placeholder="Username" required 
              />
              <input type="password" 
                     value={password} 
                     onChange={(e) => setPassword(e.target.value)} 
                     className="input" 
                     placeholder="Password" required 
              />
              <div align="center">
                <button type="submit" className="button">
                  <span>Chat Now...!</span>
                </button>
              </div>
            </form>

            <h1 className="error">{error}</h1>    
          </div>
        </div>
    
      );
}

export default Login;