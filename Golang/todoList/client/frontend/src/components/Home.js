import React, { useState } from 'react'
import TextField from '@mui/material/TextField'
import Button from '@mui/material/Button'
import { styled } from '@mui/material/styles'
import axios from 'axios'
import { RiDeleteBinLine } from 'react-icons/ri'
import { AiOutlinePlusCircle } from 'react-icons/ai'
import { GrEdit } from 'react-icons/gr'
import { FaRegEdit } from 'react-icons/fa'
import Card from 'react-bootstrap/Card'
import './Home.css'

function Home() {
  const [todo, setTodo] = useState('')
  const [allTodo, setAllTodos] = useState('')
  const [index, setIndex] = useState('')

  React.useEffect(() => {
    getAllTodos()
  }, [])

  const getAllTodos = () => {
    axios.get('http://localhost:8080/todo').then(response => {
      const allTodos = response.data.todolist
      setAllTodos(allTodos)
    })
  }

  const postTodo = () => {
    if (todo === '') {
      return
    }
    axios.post('http://localhost:8080/todo', { todo }).then(res => {
      const allTodos = res.data.todolist
      setAllTodos(allTodos)
      setTodo('')
    })
  }

  const deleteTodo = id => {
    axios.delete(`http://localhost:8080/todo/${id}`).then(response => {
      const allTodos = response.data.todolist
      setAllTodos(allTodos)
    })
  }

  const updateTodo = id => {
    const collection = document.getElementsByClassName('todoinput')
    for (let i = 0; i < allTodo.length; i++) {
      if (allTodo[i].id === id) {
        setIndex(allTodo[i].id)
        collection[i].disabled = false
        document.getElementById('outlined-basic').focus()
        document.getElementById('outlined-basic').value = `${setTodo(
          allTodo[i].todo
        )}`
      }
    }
  }

  const updateButton = id => {
    axios.put(`http://localhost:8080/todo/${id}`, { todo }).then(response => {
      const allTodos = response.data.todolist
      setAllTodos(allTodos)
    })
    const collection = document.getElementsByClassName('todoinput')
    for (let i = 0; i < allTodo.length; i++) {
      if (allTodo[i].id === id) {
        collection[i].disabled = true
        document.getElementById('outlined-basic').blur()
      }
    }
    setTodo('')
    setIndex(null)
  }

  return (
    <div className="mainDiv">
      <Card className="upperCard">
        <CssTextField
          id="outlined-basic"
          label="Add Todo"
          variant="outlined"
          value={todo}
          onChange={e => {
            setTodo(e.target.value)
          }}
          style={{ width: '60%' }}
          sx={{ input: { color: 'white' } }}
        />
        &nbsp;&nbsp;
        <Button
          variant="contained"
          size="large"
          endIcon={<AiOutlinePlusCircle />}
          className="sendButton"
          onClick={postTodo}
        >
          Add
        </Button>
        &nbsp;&nbsp;
        <Button
          variant="contained"
          size="large"
          endIcon={<FaRegEdit />}
          className="sendButton"
          onClick={() => {
            updateButton(index)
          }}
        >
          Update
        </Button>
      </Card>

      <br />

      <div className="container d-flex flex-column">
        {allTodo.length > 0 ? (
          <>
            {allTodo.map(todoo => {
              return (
                <Card className="listCard" key={todoo.id}>
                  <Card.Body className="listcardBody">
                    <input
                      type="text"
                      value={todoo.todo}
                      className="todoinput"
                      onChange={e => {
                        setTodo(e.target.value)
                      }}
                      disabled={true}
                    />

                    <Button
                      onClick={() => deleteTodo(todoo.id)}
                      style={{ color: 'black', float: 'right' }}
                    >
                      <RiDeleteBinLine style={{ fontSize: '25px' }} />
                    </Button>

                    <Button
                      onClick={() => updateTodo(todoo.id)}
                      style={{ color: 'black', float: 'right' }}
                    >
                      <GrEdit style={{ fontSize: '25px' }} />
                    </Button>
                  </Card.Body>
                </Card>
              )
            })}
          </>
        ) : (
          <h3>no todo listed</h3>
        )}
      </div>
    </div>
  )
}

const CssTextField = styled(TextField)({
  '& label.Mui-focused': {
    color: 'aliceblue',
  },
  '& .MuiInput-underline:after': {
    borderBottomColor: 'red',
  },
  '& label': {
    color: 'black',
  },
  '& multilineColor': {
    color :  'white'
  },
  '& .MuiOutlinedInput-root': {
    '& fieldset': {
      borderColor: 'blue',
      backgroundColor : 'aliceblue'
    },
    '&:hover fieldset': {
      borderColor: 'aliceblue',
      backgroundColor : 'none'
    },
    '&.Mui-focused fieldset': {
      borderColor: 'aliceblue',
      backgroundColor : '#11ffee00'
    }
  },
})

export default Home
