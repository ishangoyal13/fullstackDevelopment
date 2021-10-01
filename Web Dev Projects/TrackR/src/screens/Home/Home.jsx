import { Button, Grid, Typography } from '@material-ui/core'
import { Link } from 'react-router-dom'

import Hero from '../../assets/home.svg'
import { useStyles } from './styles'

const Home = () => {
  const classes = useStyles()

  return (
    <Grid container className={classes.wrapper}>
      <Grid item xs={12} md={6} className={classes.intro}>
        <Typography className={classes.header} variant='h3'>
          The Best Site to Track Movies
        </Typography>
        <Typography component='p' variant='h5' className={classes.subHeader}>
          Track, manage and organize movies with ease Search and discover
          without pain
          <br />
          <br />
        </Typography>
        <Link to='/add' style={{ textDecoration: 'none' }}>
          <Button
            type='submit'
            variant='contained'
            color='secondary'
            className={classes.registerButton}
          >
            Start adding
          </Button>
        </Link>
      </Grid>
      <Grid item md={5}>
        <img src={Hero} className={classes.vector} alt='hero' />
      </Grid>
    </Grid>
  )
}

export default Home
