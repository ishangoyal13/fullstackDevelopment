import React, {useState} from 'react'
import './Home.css'

function Home() {
  const [keyword,setKeyword] = useState('')
  const [search, setSearch] = useState('Nothing to show')

  const UserSubmit = async e => {
    e.preventDefault()
    try {
      const requestOptions = {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        credentials: 'include',
        body: JSON.stringify({
          keyword : keyword
        }),
      }
      const response = await fetch('http://localhost:8080/keydata', requestOptions)
      setKeyword('')
      const data = await response.json()
      const matchedKey = data.dbdata
      setSearch(matchedKey)
    } catch (err) {
      console.log(err)
    }
  }
  return (
    <div className='homeDiv'>
      <form>
        <input type="text" value={keyword} onChange={e => setKeyword(e.target.value)} />
        <input type="submit" value="Submit" onClick={(e) => UserSubmit(e)} />
        <br/>
        <textarea rows="10" style={{width : "90%"}} value={JSON.stringify(search)} readOnly></textarea>
      </form>
    </div>
  )
}

export default Home