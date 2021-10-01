import { makeStyles } from '@material-ui/core/styles'

export const useStyles = makeStyles((theme) => ({
  resultCard: {
    display: 'flex',
    alignItems: 'center',
    justifyContent: 'center',
  },
  card: {
    margin: '2rem',
    padding: '3rem',
    backgroundColor: theme.palette.primary.main,
    borderRadius: '2rem',
    width: '50rem',
  },

  poster: {
    width: '13rem',
    height: '20rem',
    borderRadius: '5px',
    color: 'transparent',
  },
  fillerPoster: {
    backgroundColor: '#dbdada',
    width: '13rem',
    height: '20rem',
    borderRadius: '5px',
    marginRight: '15px',
    display: 'block',
    color: 'transparent',
  },
  releaseDate: {
    marginTop: '2rem',
  },
  button: {
    marginTop: '10rem',
    borderRadius: '2rem',
    width: '10rem',
    height: '2rem',
    fontSize: '12px',
  },
}))
