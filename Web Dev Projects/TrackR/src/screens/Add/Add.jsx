import { useState } from 'react'
import { useDispatch, useSelector } from 'react-redux'
import { TextField, Typography } from '@material-ui/core'
import LinearProgress from '@material-ui/core/LinearProgress'
import Alert from '@material-ui/lab/Alert'

import ResultCard from '../../components/ResultCard/ResultCard'
import { searchAction } from '../../redux/actions/SearchAction'
import { useStyles } from './styles'

const Add = () => {
  const classes = useStyles()
  const dispatch = useDispatch()

  const [searchTerm, setSearchTerm] = useState('')
  const [results, setResults] = useState('')

  const { loading, movies, error } = useSelector((state) => state.search)

  const formHandling = (e) => {
    e.preventDefault()
    setSearchTerm(e.target.value)
    dispatch(searchAction(e.target.value))
    console.log(movies)
    // if (!error) {
    //   setResults(movies.results)
    // } else {
    //   setResults([])
    // }
  }

  return (
    <div className={classes.wrapper}>
      <Typography color='secondary' variant='h3' className={classes.header}>
        Add to Watchlist
      </Typography>
      <div className={classes.inputWrapper}>
        <TextField
          placeholder='Search for Movies'
          variant='outlined'
          value={searchTerm}
          onChange={formHandling}
          className={classes.search}
          InputLabelProps={{
            classes: {
              root: classes.cssLabel,
              focused: classes.cssFocused,
            },
          }}
          InputProps={{
            classes: {
              root: classes.cssOutlinedInput,
              focused: classes.cssFocused,
              notchedOutline: classes.notchedOutline,
            },
          }}
        ></TextField>
      </div>
      {loading && (
        <LinearProgress color='secondary' className={classes.loader} />
      )}
      {error && (
        <div className={classes.alert}>
          <Alert severity='error'>
            There was a problem while fetching movies
          </Alert>
        </div>
      )}
      {movies && (
        <ul className={classes.results}>
          {movies.results &&
            movies.results.map((movie, index) => (
              <ResultCard key={index} movie={movie} />
            ))}
        </ul>
      )}
    </div>
  )
}

export default Add
